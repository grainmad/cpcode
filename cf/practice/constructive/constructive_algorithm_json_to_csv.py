# https://codeforces.com/api/problemset.problems?tags=constructive algorithms
# https://codeforces.com/problemset/problem/
# "https://codeforces.com/problemset/problem/{}/{}".format(,)
import json
import os
import shutil
with open("./cf/practice/constructive/cfca.json", "r", encoding="utf8") as f:
    data = json.load(f)
    problems, problemStatistics = data["problems"], data["problemStatistics"]
    lst = [{
                "编号" : "{}{}".format(problems[i]["contestId"],problems[i]["index"]),\
                "题目" : problems[i]["name"],\
                "分数" : problems[i]["rating"] if "rating" in problems[i] else 0,\
                "标签" : ", ".join(problems[i]["tags"]), \
                "解决人数" : problemStatistics[i]["solvedCount"], \
                "链接" : "https://codeforces.com/problemset/problem/{}/{}".format(problems[i]["contestId"],problems[i]["index"])
            } 
        for i in range(len(problems))]
    lst.sort(key=lambda x:x["分数"])
# print(lst)
def check(lable):
    for i in lst:
        if i['编号'] == lable:
            return i['分数']
    return -1

# print(os.getcwd())
os.chdir("./cf/practice/constructive")
# print(os.getcwd())  
# print(os.listdir())
p = os.listdir()
print(p)
for s in p:
    sc = check(s[:-4])
    if sc != -1:
        print(s[:-4], sc)
        if not os.path.isdir(str(sc)): os.mkdir(str(sc))
        shutil.move(s, str(sc))