"""
hexo_deployer —— 将刷题仓库中的题解 markdown 同步到 Hexo 博客仓库。

扫描下列四个挂载目录，为每篇 .md 生成 Hexo front-matter 头部（标题/日期/
标签/分类/题面摘要等），再按映射写入 Hexo 博客仓库的 source/_posts 下，
默认执行 git pull -> 生成 -> git add/commit/push 完整流程：

    leetcode              -> leetcode
    cf/a-problem-everyday -> codeforces/ape
    cf/contest            -> codeforces/contest
    atcode/contest        -> atcode

需要 .env 配置（先找仓库根 REPO_ROOT/.env，再找 SCRIPT_DIR/.env（即
script/hexo/.env），参考 script/hexo/env.template）：
    CWD        cpcode 仓库根；缺省自动推导为脚本所在仓库根，一般不用填
    HEXO_BLOG  Hexo 博客仓库路径；必填，未配置时打印中文报错并以退出码 1 结束

用法：
    # 先配置 .env（复制 script/hexo/env.template 到仓库根后编辑）：
    #   HEXO_BLOG=/path/to/hexo/blog
    python3 script/hexo/hexo_deployer.py                # 全量同步，并 git pull/commit/push
    python3 script/hexo/hexo_deployer.py --no-git       # 只生成本地文件，跳过 git 操作
    python3 script/hexo/hexo_deployer.py --only leetcode # 只同步 leetcode 挂载目录
    python3 script/hexo/hexo_deployer.py --only cf/a-problem-everyday

参数/退出行为要点：
    -h        查看中文帮助，无需 .env 即可运行
    --no-git  跳过 git pull/commit/push，仅生成本地博客文件
    --only SRC 只处理挂载目录中 src 等于 SRC 的一项；无匹配项时报错退出 1
    缺少 HEXO_BLOG 配置时打印中文缺配置报错，并以退出码 1 结束
"""

import datetime
import os
import json
import time
import shutil
import argparse
import sys
from pathlib import Path
from git.repo import Repo
import requests
from dotenv import load_dotenv
import markdown
import html
from pprint import pprint
import logging

LOG_FORMAT = "%(asctime)s - %(levelname)s - %(message)s"
logging.basicConfig(level=logging.INFO, format=LOG_FORMAT)

# 路径锚点：脚本内一切仓库相对路径均由这两个锚点拼接，不依赖当前工作目录
# 脚本自身产物（配置/日志等）锚定 SCRIPT_DIR；仓库根用标记探测，脚本挪目录不失效
SCRIPT_DIR = Path(__file__).resolve().parent   # …/cpcode/script/hexo


def _find_repo_root():
    """向上探测 cb 风格仓库根：首个含 cmake/add_problem.cmake 的祖先目录。"""
    for d in SCRIPT_DIR.parents:
        if (d / "cmake" / "add_problem.cmake").is_file():
            return d
    raise SystemExit("cb-style repo root not found (cmake/add_problem.cmake 缺失)")


REPO_ROOT = _find_repo_root()                  # …/cpcode

# 以下路径仅在入口 resolve_paths() 中真正解析（保证 --help 无需 .env 也能运行）
CWD = None             # cpcode 仓库根
HEXO_BLOG = None       # Hexo 博客仓库路径
HEXO_BLOG_POST = None  # Hexo 博客文章目录 source/_posts


def resolve_paths():
    """加载 .env 并解析全局路径：CWD 缺省取仓库根，HEXO_BLOG 缺失则报错退出。"""
    global CWD, HEXO_BLOG, HEXO_BLOG_POST
    # 先试仓库根，再试脚本目录；都不存在则静默继续，靠默认值兜底
    load_dotenv(REPO_ROOT / ".env")
    load_dotenv(SCRIPT_DIR / ".env")
    # CWD 缺省用仓库根，不再依赖用户配置
    CWD = os.getenv("CWD") or str(REPO_ROOT)
    HEXO_BLOG = os.getenv("HEXO_BLOG")
    if not HEXO_BLOG:
        logging.error(
            "缺少配置 HEXO_BLOG：同步题解需要知道 Hexo 博客仓库路径。\n"
            "请在 cpcode 仓库根或 script/hexo/ 目录下创建 .env，写入：\n"
            "    HEXO_BLOG=/path/to/hexo/blog\n"
            "（可参考 script/hexo/env.template）"
        )
        sys.exit(1)
    HEXO_BLOG_POST = os.path.join(HEXO_BLOG, "source", "_posts")
    logging.info(f"CWD = {CWD}")
    logging.info(f"HEXO_BLOG = {HEXO_BLOG}")

"""
    对比 文件目录 博客目录 生成字典数据
"""
def list_files(file_path, oblog_path, ancestor):
    node = os.path.basename(file_path)
    filelines, old_bloglines = None, None
    if os.path.isfile(file_path):
        with open(file_path, "r", encoding="utf8") as f:
            filelines = f.readlines()
    if os.path.isfile(oblog_path):
        with open(oblog_path, "r", encoding="utf8") as f:
            old_bloglines = f.readlines()
    rt = {
        "name": node.replace(".md", ""),
        "type": "dir" if os.path.isdir(file_path) else "md",
        "file-lines": filelines,
        "blog-lines": old_bloglines,
        "opt": "create" if not old_bloglines else "update",
        "ancestor":ancestor.copy(),
        "son":[],
    }
    ancestor.append(node)
    if os.path.isdir(file_path):
        dir = os.listdir(file_path)
        for i in dir:
            fcur = os.path.join(file_path, i)
            ocur = os.path.join(oblog_path, i)
            if os.path.isdir(fcur) or os.path.isfile(fcur) and fcur.endswith(".md"):
                rt["son"].append(list_files(fcur, ocur, ancestor))
                ancestor.pop()
    return rt


"""
博客文章头部信息 示例
---
title: "重排水果"
date: 2023-04-09 19:03:51
updated: 2023-06-08 20:08:27
tag: ["leetcode", "思维题"]
categories: "leetcode"
mathjax: true
comments: true
description: '<ul style="text-align:left;"><p>leetcode</p><p>思维题</p></ul>'
---
"""


"""
博文默认配置

title 文件名
date 创建则当前时间，否则旧博客发布时间
updated 有内容更新，则用当前时间，否则用旧博客更新时间
tag 层级目录名
categories 根目录名
mathjax true
comments true
description 空
"""
class DefaultOption:
    def __init__(self, data):
        self.data = data
        cur_date = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        old_date = self.get_old_blog_date(data)
        self.title = self.get_blog_title()
        self.date = old_date if old_date else cur_date
        self.updated = cur_date if self.is_diff(data) else self.get_old_blog_updated(data)
        self.tag = self.get_ancestor_dir(data)
        self.categories = self.get_ancestor_dir(data)[0]
        self.mathjax = True
        self.comments = True
        self.description = ""
        # print(data)
    
    def get_blog_title(self):
        return self.data["name"]

    def gen_blog(self):
        new_blog = self.get_blog_head() + self.data['file-lines']
        # pprint(new_blog)
        return new_blog

    def get_blog_head(self):
        new_blog_head = [
            "---\n",
            # 注意title内不能有"
            f"title: \"{self.title}\"\n",
            f"date: {self.date}\n",
            f"updated: {self.updated}\n",
            "tag: [{}]\n".format(", ".join([f'\"{i}\"' for i in self.tag]) if isinstance(self.tag,list) else self.tag),
            "categories: [{}]\n".format(", ".join([f'\"{i}\"' for i in self.categories])  if isinstance(self.categories,list) else self.categories),
            # f"categories: \"{self.categories}\"\n",
            f"mathjax: {'true' if self.mathjax else 'false'}\n",
            f"comments: {'true' if self.comments else 'false'}\n",
            # 注意description内不能有'
            f"description: \'{self.description}\'\n",
            "---\n",
        ]
        # print(new_blog_head)
        return new_blog_head

    def is_diff(self, data): # 内容不同返回true
        new_blog_file = data["file-lines"]
        old_blog_file = data["blog-lines"]
        if new_blog_file and old_blog_file:
            # 尝试找到文章头部结束位置
            head_pos = 1
            while old_blog_file[head_pos] != "---\n": head_pos+=1

            return old_blog_file[head_pos+1:] != new_blog_file
        return True
    
    def get_old_blog_date(self, data):
        old_blog_file = data["blog-lines"]
        if old_blog_file and old_blog_file[2]: return old_blog_file[2][6:-1]
    
    def get_old_blog_updated(self, data):
        old_blog_file = data["blog-lines"]
        if old_blog_file and old_blog_file[3]: return old_blog_file[3][9:-1]

    def get_ancestor_dir(self, data):
        if data["ancestor"]: 
            return data["ancestor"]

    def markdown2html(self, md):
        md = '\n'.join(md)
        # print(md)
        md = html.escape(md)
        ht = markdown.markdown(md).replace("\n", "")
        # print(ht)
        return f'<ul style="text-align:left;">{ht}</ul>'
    
"""
博文leetcode配置

title 文件名
date 创建则当前时间，否则旧博客发布时间
updated 有内容更新，则用当前时间，否则用旧博客更新时间
tag 层级目录名
categories 根目录名
mathjax true
comments true
+ description 题面
"""
class LeetCodeOption(DefaultOption):
    def __init__(self, data):
        super(LeetCodeOption, self).__init__(data)
        self.description = self.leetcode_description(data)

        logging.info(f"[{'existed' if self.get_old_blog_date(data) else 'create ! ! !'}] [{'update ! ! !' if self.is_diff(data) else 'not update'}] {self.get_blog_title()}")
    
    def leetcode_description(self, data):
        new_blog_file = data["file-lines"]
        start, end = -1, -1
        for i, j in enumerate(new_blog_file):
            if j == "## 题目\n":
                start = i+1
            if j == "## 题解\n":
                end = i
        return self.markdown2html(new_blog_file[start:end])

"""
博文codeforce每日一题配置

+ title 题目名
date 创建则当前时间，否则旧博客发布时间
updated 有内容更新，则用当前时间，否则用旧博客更新时间
+ tag 题目自带的tag
+ categories codeforces
mathjax true
comments true
+ description 题面
"""
class CodeforcesAPEOption(DefaultOption):
    def __init__(self, data):
        super(CodeforcesAPEOption, self).__init__(data)
        self.title = self.get_blog_title()
        self.tag = self.get_blog_tag()
        self.categories = ["codeforces", "practice"]
        self.description = self.cfape_description(data)

        logging.info(f"[{'existed' if self.get_old_blog_date(data) else 'create ! ! !'}] [{'update ! ! !' if self.is_diff(data) else 'not update'}] {self.get_blog_title()}")

    def get_blog_title(self):
        return self.data["file-lines"][0][2:-1]

    def get_blog_tag(self):
        return ["codeforces"] + self.data["file-lines"][8][5:-1].split(', ')

    def cfape_description(self, data):
        new_blog_file = data["file-lines"]
        start, end = -1, -1
        for i, j in enumerate(new_blog_file):
            if j in ["## problem\n", "## 题意\n"]:
                start = i+1
            if j in ["## solution\n", "## 题解\n"]:
                end = i
        return self.markdown2html(new_blog_file[start:end])

"""
博文codeforce contest配置

+ title 题目名
date 创建则当前时间，否则旧博客发布时间
updated 有内容更新，则用当前时间，否则用旧博客更新时间
+ tag [codeforces, contest]
+ categories [codeforces, contest]
mathjax true
comments true
+ description 题目列表
"""
class CodeforcesContestOption(DefaultOption):
    def __init__(self, data):
        super(CodeforcesContestOption, self).__init__(data)
        self.title = self.get_blog_title()
        self.tag = ["codeforces", "contest"]
        self.categories = ["codeforces", "contest"]
        self.description = self.cfcontest_description(data)

        logging.info(f"[{'existed' if self.get_old_blog_date(data) else 'create ! ! !'}] [{'update ! ! !' if self.is_diff(data) else 'not update'}] {self.get_blog_title()}")

    def get_blog_title(self):
        return self.data["file-lines"][0][2:-1]

    def cfcontest_description(self, data):
        new_blog_file = data["file-lines"]
        return self.markdown2html(i[3:] for i in new_blog_file if i.startswith("## "))

"""
博文atcode contest配置

+ title 题目名
date 创建则当前时间，否则旧博客发布时间
updated 有内容更新，则用当前时间，否则用旧博客更新时间
+ tag [atcoder, contest]logging.info(f"{'existed' if self.get_old_blog_date(data) else 'create ! ! !'} {'update ! ! !' if self.is_diff(data) else 'not update'} {self.get_blog_title()}")
+ categories [atcoder]
mathjax true
comments true
+ description 题目列表
"""
class AtcoderContestOption(DefaultOption):
    def __init__(self, data):
        super(AtcoderContestOption, self).__init__(data)
        self.title = self.get_blog_title()
        self.tag = ["atcoder", "contest"]
        self.categories = "atcoder"
        self.description = self.atcontest_description(data)

        logging.info(f"[{'existed' if self.get_old_blog_date(data) else 'create ! ! !'}] [{'update ! ! !' if self.is_diff(data) else 'not update'}] {self.get_blog_title()}")

    def get_blog_title(self):
        return self.data["file-lines"][0][2:-1]

    def atcontest_description(self, data):
        new_blog_file = data["file-lines"]
        return self.markdown2html(i[3:] for i in new_blog_file if i.startswith("## "))


setting = {
    "mount_dirs": [
        {
            "src":"leetcode", 
            "dst":"leetcode",
            "option": lambda x : LeetCodeOption(x)
        },
        {
            "src":"cf/a-problem-everyday", 
            "dst":"codeforces/ape",
            "option": lambda x : CodeforcesAPEOption(x)
        },
        {
            "src":"cf/contest", 
            "dst":"codeforces/contest",
            "option": lambda x : CodeforcesContestOption(x)
        },
        {
            "src":"atcode/contest", 
            "dst":"atcode",
            "option": lambda x : AtcoderContestOption(x)
        }
    ]
}

def process(mdir):
    # 生成字典信息
    logging.info("generate data")
    data = list_files(os.path.join(CWD, mdir["src"]), os.path.join(HEXO_BLOG_POST, mdir["dst"]), [])
    logging.debug(data)
    def dfs(node, tmp_file_path):
        cur_path = os.path.join(tmp_file_path, node["name"])
        if node['type'] == 'dir':
            for son in node['son']:
                dfs(son, cur_path)
        else :
            os.makedirs(os.path.dirname(cur_path), exist_ok=True)
            with open(cur_path+".md", "w", encoding="utf8") as f:
                f.writelines(mdir['option'](node).gen_blog())

    tmpdir = os.path.join(CWD, "tmp")
    newblog = os.path.join(tmpdir, os.path.basename(mdir['src']))
    oldblog = os.path.join(HEXO_BLOG_POST, mdir["dst"])
    # print(newblog, oldblog)
    # 将转化结果存至tmp下
    logging.info("generate blog dir at /tmp")
    dfs(data, tmpdir)
    
    # 替换博客项目的文件夹 
    logging.info("replace old blog dir")
    if os.path.isdir(oldblog):
        logging.info("exist old blog, remove it!")
        shutil.rmtree(oldblog)
    shutil.copytree(newblog, oldblog) # oldblog 不存在的父级目录也会创建
    # 删除临时文件 
    logging.info("remove /tmp file")
    shutil.rmtree(newblog)

def processAll(only=None):
    for i in setting["mount_dirs"]:
        # --only 只处理 src 等于给定值的一项，其余跳过
        if only is not None and i["src"] != only:
            logging.info(f"skip {i['src']} (--only)")
            continue
        logging.info(f"process {i}")
        process(i)

# processAll()
def run(bygit = False, only = None):
    if bygit:
        logging.warning("已开启git操作")
        repo = Repo(HEXO_BLOG)
        logging.info("git pull")
        repo.git.pull("--rebase")
        processAll(only)
        logging.info("git add -all")
        repo.git.add("--all")
        logging.info("git commit")
        repo.git.commit("-m auto update by [bot] hexo-deployer v2.0")
        logging.info("git push")
        repo.git.push()
    else:
        processAll(only)


def parse_args():
    parser = argparse.ArgumentParser(
        description="同步刷题题解 markdown 到 Hexo 博客仓库：为每篇 .md 生成 front-matter 头部，"
                    "按挂载目录映射写入 HEXO_BLOG/source/_posts，默认附带 git pull/commit/push。",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""用法示例：
  # 先配置 .env（可复制 script/hexo/env.template 到仓库根后编辑）：
  #   HEXO_BLOG=/path/to/hexo/blog
  python3 script/hexo/hexo_deployer.py             # 全量同步，并 git pull/commit/push
  python3 script/hexo/hexo_deployer.py --no-git    # 只生成本地文件，跳过 git 操作
  python3 script/hexo/hexo_deployer.py --only leetcode # 只同步 leetcode 挂载目录
  python3 script/hexo/hexo_deployer.py --only cf/a-problem-everyday

挂载目录映射：
  leetcode              -> leetcode
  cf/a-problem-everyday -> codeforces/ape
  cf/contest            -> codeforces/contest
  atcode/contest        -> atcode
""")
    parser.add_argument("--no-git", action="store_true",
                        help="跳过 git pull/commit/push，只在本地生成博客文件（默认执行完整 git 流程）")
    parser.add_argument("--only", metavar="SRC",
                        help="只处理挂载目录中 src 等于该值的一项，如 --only leetcode、--only cf/a-problem-everyday")
    return parser.parse_args()


if __name__ == "__main__":
    args = parse_args()
    # --only 合法性校验：必须是挂载目录之一的 src（无需 .env 即可判定）
    if args.only and all(m["src"] != args.only for m in setting["mount_dirs"]):
        logging.error("未找到 src 为 '{}' 的挂载目录，可选值：{}".format(
            args.only, "、".join(m["src"] for m in setting["mount_dirs"])))
        sys.exit(1)
    resolve_paths()
    run(bygit=not args.no_git, only=args.only)