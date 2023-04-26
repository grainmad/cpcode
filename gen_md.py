
import argparse
import os
import sys
import json
import os
import time

import git


# # F. Asya And Kittens
#
# https://codeforces.com/problemset/problem/1131/F
#
# ## 题意


# ## 题解


# ## 代码

# ``` cpp

# ```

def create_md(path, info):
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
        f.write("## 题意")
        f.write("\n\n\n\n")
        f.write("## 题解")
        f.write("\n\n\n\n")
        f.write("## 代码\n\n")
        f.write("``` cpp\n")
        with open(path+".cpp", "r", encoding="utf8") as g:
            f.write(g.read())
        f.write("\n```")
    print(path+".md generate success")


def md_info(md_file):
    with open("./data/all.json", "r", encoding="utf8") as f:
        data = json.load(f)
        problems, problemStatistics = data["problems"], data["problemStatistics"]
        lst = {"{}{}".format(problems[i]["contestId"], problems[i]["index"]): {
            "编号": "{}{}".format(problems[i]["contestId"], problems[i]["index"]),
            "题目": problems[i]["name"],
            "分数": problems[i]["rating"] if "rating" in problems[i] else 0,
            "标签": ", ".join(problems[i]["tags"]),
            "解决人数": problemStatistics[i]["solvedCount"],
            "链接": "https://codeforces.com/problemset/problem/{}/{}".format(problems[i]["contestId"], problems[i]["index"])
        }
            for i in range(len(problems))}
        if md_file in lst:
            return lst[md_file]
        return {}


def dfs(path, gen_file):
    dir = os.listdir(path)
    for i in dir:
        cur = path+"/"+i
        if os.path.isdir(cur):
            # print(cur, "isdir")
            if dfs(cur, gen_file):
                return True
        if i[-4:] == ".cpp" and i[:-4] == gen_file:
            # print(cur, "isfile")
            if os.path.isfile(cur[:-4]+".md"):
                print("existed", cur[:-4]+".md")
            else:
                info = md_info(gen_file)
                # print(info)
                if info == {}:
                    print("no find info")
                else:
                    create_md(cur[:-4], info)
            return True
    return False


def gen_md(files):
    print("gen files:", files)
    for i in files:
        print(i, end=": ")
        if not dfs(".", i):
            print("no "+i+".cpp")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='auto gen .md by .cpp')

    # 添加命令行参数
    parser.add_argument('--input', "-i", type=str, nargs="*",
                        help="gen by input cpp files (no suffix)")
    parser.add_argument('--git', "-g", action="store_true",
                        help="gen by git untracked cpp files")

    # 从命令行中结构化解析参数
    args = parser.parse_args()
    # print(args)
    arg_i = args.input
    arg_g = args.git
    # print('show {}  {}'.format(arg_i, arg_g))
    if arg_i is not None:
        gen_md(arg_i)
    elif arg_g:
        repo = git.Repo('.')
        msg = repo.git.status()
        li = msg.split('\n')
        # print(li)
        cpp = [i.split('/')[-1][:-4] for i in li if i[-4:] == '.cpp']
        gen_md(cpp)
    else:
        parser.print_help()

    # print('参数个数为:', len(sys.argv), '个参数。')
    # print('参数列表:', str(sys.argv))
    # for i in range(1, len(sys.argv)):
    #     print(sys.argv[i], end=": ")
    #     if not dfs(".", sys.argv[i]):
    #         print("no "+sys.argv[i]+".cpp")
