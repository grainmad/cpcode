
import datetime
import os
import json
import time
import shutil
from git.repo import Repo
import requests
from dotenv import load_dotenv
import markdown
import html
from pprint import pprint

load_dotenv()

CWD = os.getenv("CWD")
HEXO_BLOG = os.getenv("HEXO_BLOG")
HEXO_BLOG_POST = os.path.join(HEXO_BLOG, "source", "_posts")

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
        self.title = data["name"]
        self.date = old_date if old_date else cur_date
        self.updated = cur_date if self.is_diff(data) else self.get_old_blog_updated(data)
        self.tag = self.get_ancestor_dir(data)
        self.categories = self.get_ancestor_dir(data)[0]
        self.mathjax = True
        self.comments = True
        self.description = ""
        # print(data)
    
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
    
    def leetcode_description(self, data):
        new_blog_file = data["file-lines"]
        start, end = -1, -1
        for i, j in enumerate(new_blog_file):
            if j == "## 题目\n":
                start = i+1
            if j == "## 解题\n":
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
+ tag [atcoder, contest]
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
    data = list_files(os.path.join(CWD, mdir["src"]), os.path.join(HEXO_BLOG_POST, mdir["dst"]), [])
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
    dfs(data, tmpdir)
    
    # 替换博客项目的文件夹 
    if os.path.isdir(oldblog):
        shutil.rmtree(oldblog)
    # os.makedirs(os.path.dirname(oldblog), exist_ok=True)
    shutil.copytree(newblog, oldblog) # oldblog 不存在的父级目录也会创建
    # 删除临时文件 
    shutil.rmtree(newblog)

def processAll():
    for i in setting["mount_dirs"]:
        process(i)

# processAll()
def run(bygit = False):
    if bygit:
        repo = Repo(HEXO_BLOG)
        repo.git.pull("--rebase")
        processAll()
        repo.git.add("--all")
        repo.git.commit("-m auto update by [bot] hexo-deployer v2.0")
        repo.git.push()
    else:
        processAll()


if __name__ == "__main__":
    run(True)