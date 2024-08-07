import requests
from lxml import etree
import datetime
import json
import logging
import os
import random
import time



cwd = "./cf/a-problem-everyday/"  # 当前脚本相对项目工作目录位置
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
    for(auto [x,y]:mp) { if (s) s = 0; else os << ", "; os<<x<<": "<<y; }
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
    url = 'https://www.luogu.com.cn/problem/'+qid
    head = {
        'Referer': 'https://www.lougu.com.cn/',
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36'
    }
    response = requests.get(url, headers=head)
    html = response.text
    if "出错了" in html:
        return ""
    # print(html)
    html_element = etree.HTML(html)
    mean = html_element.xpath(
            '//article/div/text()')[0]
    return mean

def init_log(logfile):
    LOG_FORMAT = '[%(asctime)s][%(levelname)s][- %(message)s]'
    # logging.basicConfig(filename='autoMerge.log',
    #                     level=logging.DEBUG, format=LOG_FORMAT, handlers=logging.StreamHandler())
    # 第一步：创建日志器对象，默认等级为warning
    logger = logging.getLogger("gen-problem")
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


def random_problem(all_problems):
    # condition = {
    #     "contestId-lest": 1000,
    #     "rating-lest": 1800,
    #     "rating-most": 2100,
    #     # [] 空则选取所有标签
    #     "include-tags": [], #["constructive algorithms", "greedy", "math", "dp"]
    #     "exclude-tags": [""]
    # }
    with open('ape-setting.json', 'r', encoding='utf8') as f:
        condition = json.load(f)
    filtered_problems = problems_filter(condition, all_problems)
    # print(filtered_problems, len(filtered_problems))

    existed_problems = get_existed_promblems(cwd)
    # print(existed_problems, len(existed_problems))

    remain_problems = filtered_problems-existed_problems
    # print(remain_problems, len(remain_problems))

    sz = len(remain_problems)
    return list(remain_problems)[random.randrange(0, sz)]


def create_file(path, info):
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
        f.write(get_question_meaning("CF"+info['编号']))
        f.write("\n\n")
        f.write("## solution")
        f.write("\n\n\n\n")
        f.write("## code\n\n")
        f.write("``` cpp\n\n")
        f.write("```\n")
    logger.info(path+".md generate success")


def gen_related_file(problem, all_problems):
    dirs = cwd+datetime.date.today().strftime('%Y/%m/%d/')
    if not os.path.exists(dirs):
        os.makedirs(dirs)
    logger.info(all_problems[problem])
    create_file(dirs+problem, all_problems[problem])


if __name__ == "__main__":
    logger = init_log(cwd+"log-gen-problem.log")
    all_problems = load_data("./data/cf/cf-all.json")
    problem = random_problem(all_problems)
    gen_related_file(problem, all_problems)
