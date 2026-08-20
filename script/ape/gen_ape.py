"""CF 每日一题随机选题脚本。

从题库数据（script/ape/cf-all.json）中按配置文件 ape_setting.json 的筛选条件，
随机选出一道尚未做过的 Codeforces 题目，在仓库 cf/a-problem-everyday/<年>/<月>/<日>/
下生成 <题号>.cpp 代码骨架与 <题号>.md 题目笔记（题面通过洛谷抓取），并记录日志。
脚本从任意目录运行均可，内部路径全部锚定到脚本所在位置。

用法:
    python3 script/ape/gen_ape.py                    # 随机选一题并生成文件（默认行为）
    python3 script/ape/gen_ape.py --dry-run          # 仅随机选题并打印信息，不创建文件、不请求洛谷
    python3 script/ape/gen_ape.py --setting my.json  # 覆盖默认配置文件路径
    python3 script/ape/gen_ape.py --data my/cf-all.json  # 覆盖默认题库数据路径

参数 / 退出行为要点:
    --setting PATH  配置文件路径，默认 script/ape/ape_setting.json；不存在时自动从
                    ape_setting.json.template 复制一份并给出提示。
    --data PATH     题库数据文件路径，默认 script/ape/cf-all.json。
    --dry-run       只打印所选题目与信息后以退出码 0 结束。
    无参数时行为与原脚本完全一致；筛选后无剩余题目或配置文件缺失时打印中文提示并以退出码 1 结束。

配置文件 ape_setting.json 字段说明（可参考 ape_setting.json.template）:
    contestId-lest  只保留比赛编号（contestId）不小于该值的题目
    rating-lest     只保留分数（rating）不小于该值的题目
    rating-most     只保留分数（rating）不大于该值的题目
    include-tags    需要包含的标签列表，命中任一即保留；空列表 [] 表示不限标签
    exclude-tags    需要排除的标签列表，命中任一即排除
"""
import argparse
import datetime
import json
import logging
import os
import random
import shutil
import sys
import time
from pathlib import Path

import requests
from lxml import etree


# 路径锚点：脚本自身的配置/日志/数据都锚定 SCRIPT_DIR，不依赖当前工作目录
SCRIPT_DIR = Path(__file__).resolve().parent   # …/cpcode/script/ape


def _find_repo_root():
    # 仓库根不做目录层数假设（脚本位置可能再调整），改靠仓库标记文件逐级向上探测
    for d in SCRIPT_DIR.parents:
        if (d / "cmake" / "add_problem.cmake").is_file():
            return d
    raise SystemExit("cb-style repo root not found (cmake/add_problem.cmake 缺失)")


REPO_ROOT = _find_repo_root()                  # …/cpcode

# 每日一题输出目录：题目生成、遍历排除已做题都基于它
OUTPUT_DIR = REPO_ROOT / "cf" / "a-problem-everyday"

cpp_template = '''
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

random_device seed;
ranlux48 engine(seed());
int random(int l, int r) {
    uniform_int_distribution<> distrib(l, r);
    return distrib(engine);
}
template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p) {
    return os<<'['<<p.first<<", "<<p.second<<']';
}
template<class t> ostream& operator<<(ostream& os,const vector<t>& v) {
    os<<'['; int s = 1;
    for(auto e:v) { if (s) s = 0; else os << ", "; os << e; }
    return os<<']';
}
template<class t,class u> ostream& operator<<(ostream& os,const map<t,u>& mp){
    os<<'{'; int s = 1;
    for(auto [x,y]:mp) { if (s) s = 0; else os<<x<<": "<<y; }
    return os<<'}';
}

void sol() {

}

int main() {
    cout << setprecision(15) << fixed;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef SINGLE_INPUT
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
#else
    sol();
#endif
    return 0;
}
'''
def get_question_meaning(qid):
    """抓取洛谷题面（题目描述部分）。

    洛谷页面结构曾为 article/div，现为 article/section/div，因此按优先级依次
    尝试候选 xpath；全部落空时兜底抽取 article 的整体文本。任何一步失败都只
    返回空字符串并记录日志，绝不让异常向上传播（避免 .md 写到一半才崩溃）。
    """
    url = 'https://www.luogu.com.cn/problem/'+qid
    head = {
        'Referer': 'https://www.lougu.com.cn/',
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36'
    }
    try:
        response = requests.get(url, headers=head, timeout=30)
    except requests.RequestException as e:
        logger.warning("请求洛谷 {} 失败（{}），题面留空。".format(url, e))
        return ""
    html = response.text
    if "出错了" in html:
        return ""
    html_element = etree.HTML(html)
    if html_element is None:
        logger.warning("洛谷 {} 返回内容无法解析为 HTML，题面留空。".format(url))
        return ""
    # 候选 xpath：第一个命中的文本节点即“题目描述”小节的正文
    candidate_xpaths = [
        '//article/section/div/text()',  # 现行结构：article/section/div
        '//article/div/text()',          # 旧版结构，保留兼容
    ]
    for xpath in candidate_xpaths:
        nodes = html_element.xpath(xpath)
        if nodes and str(nodes[0]).strip():
            return nodes[0]
    # 兜底：候选 xpath 全部落空（页面结构又变了）时，直接抽取题面区块文本
    sections = html_element.xpath('//article/section')
    if sections:
        return ''.join(sections[0].itertext()).strip()
    articles = html_element.xpath('//article')
    if articles:
        return ''.join(articles[0].itertext()).strip()
    logger.warning("未能从洛谷 {} 页面中定位题面（页面结构可能已变化），题面留空。".format(url))
    return ""

def init_log(logfile):
    LOG_FORMAT = '[%(asctime)s][%(levelname)s][- %(message)s]'
    # logging.basicConfig(filename='autoMerge.log',
    #                     level=logging.DEBUG, format=LOG_FORMAT, handlers=logging.StreamHandler())
    # 第一步：创建日志器对象，默认等级为warning
    logger = logging.getLogger("gen_ape")
    # logging.basicConfig(level="DEBUG")
    logger.setLevel("INFO")
    # 第二步：创建控制台日志处理器+文件日志处理器
    console_handler = logging.StreamHandler()
    file_handler = logging.FileHandler(
        logfile, mode="a", encoding="utf-8")
    # 第三步：设置控制台日志的输出级别,需要日志器也设置日志级别为info；----根据两个地方的等级进行对比，取日志器的级别
    fmt1 = logging.Formatter(fmt=LOG_FORMAT)
    fmt2 = logging.Formatter(fmt=LOG_FORMAT)
    # 第四步：设置控制台日志和文件日志的输出格式
    console_handler.setFormatter(fmt1)
    file_handler.setFormatter(fmt2)
    # 第五步：将控制台日志器、文件日志器，添加进日志器对象中
    logger.addHandler(console_handler)
    logger.addHandler(file_handler)
    return logger


def load_data(path):
    with open(path, "r", encoding="utf8") as f:
        data = json.load(f)
        problems, problemStatistics = data["problems"], data["problemStatistics"]
        all_problems = {"{}{}".format(problems[i]["contestId"], problems[i]["index"]): {
            "contestId":problems[i]["contestId"],
            "编号": "{}{}".format(problems[i]["contestId"], problems[i]["index"]),
            "题目": problems[i]["name"],
            "分数": problems[i]["rating"] if "rating" in problems[i] else 0,
            "标签": ", ".join(problems[i]["tags"]),
            "解决人数": problemStatistics[i]["solvedCount"],
            "链接": "https://codeforces.com/problemset/problem/{}/{}".format(problems[i]["contestId"], problems[i]["index"])
        }
            for i in range(len(problems))}
    return all_problems


def problems_filter(condition, all_problems):
    return set(k for k, v in all_problems.items()
               if condition["rating-lest"] <= v['分数'] <= condition["rating-most"]
               and (not condition['include-tags'] or set(v['标签'].split(", ")) & set(condition['include-tags']))
               and condition["contestId-lest"] <= v['contestId']
               and not set(v['标签'].split(", ")) & set(condition['exclude-tags'])
               )


def get_existed_promblems(dir):
    suffix = [
        'cpp',
        # 'txt'
    ]
    st = set()

    def dfs(path):
        dir = os.listdir(path)
        for i in dir:
            cur = path+"/"+i
            if os.path.isdir(cur):
                # print(cur, "isdir")
                dfs(cur)
            if os.path.isfile(cur):
                # print(cur, "isfile")
                # print(cur.split('.')[-1])
                sp = i.split('.')
                if sp[-1] in suffix:
                    st.add(sp[0])
    dfs(dir)
    return st


def ensure_setting(setting_path):
    # 配置文件不存在时，自动从模板复制一份，便于首次使用
    if setting_path.exists():
        return setting_path
    template = SCRIPT_DIR / "ape_setting.json.template"
    if template.exists():
        shutil.copyfile(template, setting_path)
        print("未找到配置文件 {}，已自动从模板 {} 复制生成，可按需修改筛选条件后重新运行。".format(setting_path, template))
        return setting_path
    print("未找到配置文件 {}，且模板 {} 也不存在，请先创建配置文件再运行。".format(setting_path, template))
    sys.exit(1)


def random_problem(all_problems, setting_path):
    # 筛选条件字段含义见模块 docstring 与 ape_setting.json.template
    with open(setting_path, 'r', encoding='utf8') as f:
        condition = json.load(f)
    filtered_problems = problems_filter(condition, all_problems)
    # print(filtered_problems, len(filtered_problems))

    existed_problems = get_existed_promblems(str(OUTPUT_DIR))
    # print(existed_problems, len(existed_problems))

    remain_problems = filtered_problems-existed_problems
    # print(remain_problems, len(remain_problems))

    sz = len(remain_problems)
    if sz == 0:
        print("筛选后没有剩余可选题目，建议放宽 {} 中的筛选条件"
              "（如降低 rating-lest、提高 rating-most、清空 include-tags）后重试。".format(setting_path))
        sys.exit(1)
    return list(remain_problems)[random.randrange(0, sz)]


def create_file(path, info):
    # 先抓取题面再动笔：get_question_meaning 保证不抛异常，网络失败只会得到空串，
    # 这样即使洛谷抓取失败也不会留下写到一半的 .md 文件
    meaning = get_question_meaning("CF"+info['编号'])
    with open(path+".cpp", 'w', encoding="utf8") as f:
        f.write(cpp_template)
    with open(path+".md", 'w', encoding="utf8") as f:
        f.write("# ")
        f.write(info['题目'])
        f.write("\n\n")
        f.write("Created by LXC on "+time.ctime())
        f.write("\n\n")
        f.write(info['链接'])
        f.write("\n\n")
        f.write("ranting: "+str(info['分数']))
        f.write("\n\n")
        f.write("tag: "+info['标签'])
        f.write("\n\n")
        f.write("## problem")
        f.write("\n\n")
        f.write(meaning)
        f.write("\n\n")
        f.write("## solution")
        f.write("\n\n\n\n")
        f.write("## code\n\n")
        f.write("``` cpp\n\n")
        f.write("```\n")
    logger.info(path+".md generate success")


def gen_related_file(problem, all_problems):
    dirs = OUTPUT_DIR / datetime.date.today().strftime('%Y/%m/%d')
    if not os.path.exists(dirs):
        os.makedirs(dirs)
    logger.info(all_problems[problem])
    create_file(str(dirs / problem), all_problems[problem])


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="CF 每日一题：按 ape_setting.json 的筛选条件随机选一道未做过的题目，"
                    "并在 cf/a-problem-everyday/<年>/<月>/<日>/ 下生成 .cpp 与 .md 文件",
        epilog="用法示例:\n"
               "  python3 script/ape/gen_ape.py                        # 随机选一题并生成文件\n"
               "  python3 script/ape/gen_ape.py --dry-run              # 仅打印所选题目，不生成文件、不请求洛谷\n"
               "  python3 script/ape/gen_ape.py --setting my.json      # 覆盖默认配置文件路径\n"
               "  python3 script/ape/gen_ape.py --data my/cf-all.json  # 覆盖默认题库数据路径\n"
               "\n"
               "配置文件 ape_setting.json 字段: contestId-lest/rating-lest/rating-most 为数值下上限；\n"
               "include-tags 为需命中的标签列表（空列表不限），exclude-tags 为需排除的标签列表。",
        formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--setting', type=str, metavar="PATH",
                        help="配置文件路径（默认 script/ape/ape_setting.json，缺失时自动从模板复制）")
    parser.add_argument('--data', type=str, metavar="PATH",
                        help="题库数据文件路径（默认 script/ape/cf-all.json）")
    parser.add_argument('--dry-run', action="store_true",
                        help="仅随机选题并打印所选题目与信息，不创建文件、不请求洛谷")
    args = parser.parse_args()

    logger = init_log(SCRIPT_DIR / "gen_ape.log")

    data_path = Path(args.data) if args.data else SCRIPT_DIR / "cf-all.json"
    setting_path = ensure_setting(
        Path(args.setting) if args.setting else SCRIPT_DIR / "ape_setting.json")

    all_problems = load_data(data_path)
    problem = random_problem(all_problems, setting_path)

    if args.dry_run:
        logger.info("dry-run：本次选中题目（仅预览，不生成文件、不请求洛谷）")
        logger.info(all_problems[problem])
        sys.exit(0)

    gen_related_file(problem, all_problems)
