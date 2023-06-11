
import datetime
import os
import json
import time
from git.repo import Repo
import requests


def request_leetcode_tag(titleSlug):
    # requests.packages.urllib3.contrib.pyopenssl.extract_from_urllib3()
    url = 'https://leetcode.cn/graphql/'
    head = {
        'Accept': '*/*',
        'Accept-Encoding': 'gzip, deflate, br',
        'Accept-Language': 'en-GB',
        'Content-Type': 'application/json',
        'Host': 'leetcode.cn',
        'Origin': 'https://leetcode.cn',
        'Pragma': 'no-cache',
        'Sec-Ch-Ua': '"Not.A/Brand";v="8", "Chromium";v="114", "Google Chrome";v="114"',
        'Sec-Ch-Ua-Mobile': '?0',
        'Sec-Ch-Ua-Platform': '"Windows"',
        'Sec-Fetch-Dest': 'empty',
        'Sec-Fetch-Mode': 'cors',
        'Sec-Fetch-Site': 'same-origin',
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36',
        'X-Csrftoken': 'x7yqDMZ8NuwkU6r8KQaseIn4wTqtNcuAinf7rtHKHgYEyZEoislOjiepZreLD7vi',
        'X-Definition-Name': 'question',
        'X-Operation-Name': 'questionData',
        'X-Timezone': 'Asia/Shanghai'
    }
    data = {
        "operationName": "questionData",
        "variables": {
            "titleSlug": titleSlug
        },
        "query": "query questionData($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    questionId\n    questionFrontendId\n    categoryTitle\n    boundTopicId\n    title\n    titleSlug\n    content\n    translatedTitle\n    translatedContent\n    isPaidOnly\n    difficulty\n    likes\n    dislikes\n    isLiked\n    similarQuestions\n    contributors {\n      username\n      profileUrl\n      avatarUrl\n      __typename\n    }\n    langToValidPlayground\n    topicTags {\n      name\n      slug\n      translatedName\n      __typename\n    }\n    companyTagStats\n    codeSnippets {\n      lang\n      langSlug\n      code\n      __typename\n    }\n    stats\n    hints\n    solution {\n      id\n      canSeeDetail\n      __typename\n    }\n    status\n    sampleTestCase\n    metaData\n    judgerAvailable\n    judgeType\n    mysqlSchemas\n    enableRunCode\n    envInfo\n    book {\n      id\n      bookName\n      pressName\n      source\n      shortDescription\n      fullDescription\n      bookImgUrl\n      pressImgUrl\n      productUrl\n      __typename\n    }\n    isSubscribed\n    isDailyQuestion\n    dailyRecordStatus\n    editorType\n    ugcQuestionId\n    style\n    exampleTestcases\n    jsonExampleTestcases\n    __typename\n  }\n}\n"
    }

    response = requests.post(url, headers=head, data=json.dumps(data))
    html = response.text
    # print(html)
    dc = json.loads(html)
    # print([i['translatedName'] for i in dc['data']['question']['topicTags']])
    return [i['translatedName'] for i in dc['data']['question']['topicTags']]


if __name__ == "__main__":
    # Mount directory as hexo blog
    with open('hexo-deployer-setting.json', 'r', encoding='utf8') as f:
        setting = json.load(f)
    repo_path = setting["repo_path"]
    blog_path = repo_path+"/source/_posts"
    mount_dirs = ["leetcode", "cf/a-problem-everyday",
                  "cf/contest", 'atcode/contest']

    repo = Repo(repo_path)
    repo.git.pull("--rebase")

    blog_list = os.listdir(blog_path)
    # print(blog_list)

    def gen_blog(id, path):
        sp = path.split('/')
        # print(sp)
        # ---
        # title: 母函数
        # date: 2023-01-06 17:58:53
        # updated: 2023-01-06 17:58:53
        # tags:
        # - 母函数
        # - 组合数学
        # categories: 组合数学
        # mathjax: true
        # comments: true
        # description: 组合数学笔记——母函数
        # author: lxc
        # ---

        def get_datetime(file):
            if sp[-1] not in blog_list:
                return datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
            with open(file, 'r', encoding="utf8") as f:
                txt = f.readlines()
                if len(txt) >= 2 and txt[2][:5] == "date:":
                    return txt[2][6:-1]
            return datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        old_blog_file = blog_path+"/"+sp[-1]

        # 默认文章配置
        blog_head = {
            "title": sp[-1][:-3],  # string
            "date": get_datetime(old_blog_file),  # time
            "updated": datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S'),  # time
            "tag": sp[:-1],  # list
            "categories": sp[0],  # string
            "mathjax": True,  # true or false
            "comments": True,  # true or false
            "description": sp[:-1]  # list
        }
        # 自定义各个文件夹的文章配置
        # if id == 0: # leetcode
        #     with open(path, 'r', encoding="utf8") as f:
        #         txt = f.readlines()
        #         tags = request_leetcode_tag(
        #             (txt[2].split('](')[-1]).split('/')[-2])
        #     time.sleep(5)
        if id == 1:  # cf a problem everyday
            with open(path, 'r', encoding="utf8") as f:
                txt = f.readlines()
                blog_head['title'] += " "+txt[0][2:].strip()
                blog_head['tag'] = ['cf'] + txt[8][5:-1].split(', ')
                if "## problem\n" in txt and "## solution\n" in txt:
                    blog_head['description'] = txt[txt.index(
                        "## problem\n")+1: txt.index("## solution\n")]
                if "## 题意\n" in txt and "## 题解\n" in txt:
                    blog_head['description'] = txt[txt.index(
                        "## 题意\n")+1: txt.index("## 题解\n")]
                blog_head['description'] = [i.strip()
                                            for i in blog_head['description'] if i.strip()]
        if id == 2:  # cf contest
            blog_head['tag'] = ['cf', 'contest']
            with open(path, 'r', encoding="utf8") as f:
                txt = f.readlines()
                if txt[0][:2] == "# ":
                    blog_head['title'] = txt[0][2:].strip()
                pbt = [i[3:].strip() for i in txt if i[:3] == '## ']
                if pbt:
                    blog_head['description'] = pbt
        if id == 3:  # atcode contest
            blog_head['tag'] = ['atcode', 'contest']
            with open(path, 'r', encoding="utf8") as f:
                txt = f.readlines()
                if txt[0][:2] == "# ":
                    blog_head['title'] = txt[0][2:].strip()
                pbt = [i[3:].strip() for i in txt if i[:3] == '## ']
                if pbt:
                    blog_head['description'] = pbt

        new_blog_file = [
            "---\n",
            # 注意title内不能有"
            "title: \""+blog_head['title']+"\"\n",
            "date: "+blog_head['date']+"\n",
            "updated: " + blog_head['updated'] + "\n",
            "tag: [" + ", ".join(blog_head['tag'])+"]\n",
            "categories: " + blog_head['categories'] + "\n",
            "mathjax: " + ("true" if blog_head['mathjax'] else "false") + "\n",
            "comments: " +
            ("true" if blog_head['comments'] else "false") + "\n",
            # 注意description内不能有'
            "description: '" + '<br>'.join(blog_head['description']) + "'\n",
            "---\n",
        ]
        # new_blog_file.append("---\n")
        # new_blog_file.append("title: "+sp[-1][:-3]+"\n")
        # new_blog_file.append("date: "+get_datetime(old_blog_file)+"\n")
        # new_blog_file.append(
        #     "updated: " + datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S') + "\n")
        # new_blog_file.append("tag:\n")
        # for i in tags:
        #     new_blog_file.append("- "+i+"\n")
        # new_blog_file.append("categories: "+sp[0]+"\n")
        # new_blog_file.append("mathjax: true\n")
        # new_blog_file.append("comments: true\n")
        # ds = ["description:"]
        # for i in tags:
        #     ds.append(" "+i)
        # ds.append("\n")
        # new_blog_file.append(''.join(ds))
        # new_blog_file.append("author: lxc\n")
        # new_blog_file.append("---\n")
        with open(path, "r", encoding="utf8") as g:
            new_blog_file += g.readlines()

        if sp[-1] in blog_list:  # 已存在同名文件，除更新无差别，则不用更改
            cp_file = new_blog_file.copy()
            del (cp_file[3])
            with open(old_blog_file, 'r', encoding="utf8") as f:
                txt = f.readlines()
                if len(txt) > 3:
                    del (txt[3])
                # print(txt)
                # print(cp_file)

                # os.system("pause")
                if txt == cp_file:
                    print("not modified", old_blog_file)
                    return

        with open(old_blog_file, 'w', encoding="utf8") as f:
            f.writelines(new_blog_file)
        print("generate success", old_blog_file)

    def dfs(id, path):
        dir = os.listdir(path)
        for i in dir:
            cur = path+"/"+i
            if os.path.isdir(cur):
                dfs(id, cur)
            if os.path.isfile(cur):
                # print(cur)
                if cur[-3:] == '.md':
                    gen_blog(id, cur)

    for id, mount_dir in enumerate(mount_dirs):
        dfs(id, mount_dir)

    repo.git.add("--all")
    repo.git.commit("-m auto update by hexo-deployer")
    repo.git.push()
