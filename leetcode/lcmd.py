import requests
import json
import html2text as ht
from fake_useragent import UserAgent

def get_problem_md(title):
    
    ua = UserAgent()
    # for i in range(10):
    #     print(ua.random)

    url = 'https://leetcode.cn/graphql/'
    # head = {
    #     'Accept': '*/*',
    #     'Accept-Encoding': 'gzip, deflate, br',
    #     'Accept-Language': 'en-GB',
    #     'Content-Type': 'application/json',
    #     'Host': 'leetcode.cn',
    #     'Origin': 'https://leetcode.cn',
    #     'Pragma': 'no-cache',
    #     'Sec-Ch-Ua': '"Not.A/Brand";v="8", "Chromium";v="114", "Google Chrome";v="114"',
    #     'Sec-Ch-Ua-Mobile': '?0',
    #     'Sec-Ch-Ua-Platform': '"Windows"',
    #     'Sec-Fetch-Dest': 'empty',
    #     'Sec-Fetch-Mode': 'cors',
    #     'Sec-Fetch-Site': 'same-origin',
    #     'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36',
    #     'X-Csrftoken': 'x7yqDMZ8NuwkU6r8KQaseIn4wTqtNcuAinf7rtHKHgYEyZEoislOjiepZreLD7vi',
    #     'X-Definition-Name': 'question',
    #     'X-Operation-Name': 'questionData',
    #     'X-Timezone': 'Asia/Shanghai'
    # }
    head = {
        "Host": "leetcode.cn",
        # "User-Agent": "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:123.0) Gecko/20100101 Firefox/123.0",
        "User-Agent": ua.random,
        # "Accept": "*/*",
        # "Accept-Language": "zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2",
        # "Accept-Encoding": "gzip, deflate, br",
        "content-type": "application/json",
        # "x-csrftoken": "ZybjCuEgrZEmNkTp4kbbhXj9x69vyWFDtIW0vzEPr5L32vNzULOZ8MxQf9Ao38su",
        # "random-uuid": "17331067-5d5d-bbb7-ac73-15ff6f30e7a6",
        # "uuuserid": "4e0bf42bde0bbce1244a7569bf876438",
        # "sentry-trace": "17845ed999604d7da09fe02b0b363118-8f3a1efcd2dddfd0-1"    
    }
    data = {
        "query":"\n    query questionTranslations($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    translatedTitle\n    translatedContent\n  }\n}\n    ",
        "variables":{
            "titleSlug":title
        },
        "operationName":"questionTranslations"
    }
    print(head)
    # print(html)
    response = requests.post(url, headers=head, data=json.dumps(data))
    html = response.text
    dc = json.loads(html)
    title = dc['data']['question']['translatedTitle']
    html_content = dc['data']['question']['translatedContent']

    text_maker = ht.HTML2Text()
    markdown_content = text_maker.handle(html_content)
    return title, markdown_content



def gen_file(slug):
    url = "https://leetcode.cn/problems/"+slug+"/"
    title, text = get_problem_md(slug)

    with open(title+".md", 'w', encoding="utf8") as f:
            f.write("## 题目")
            f.write("\n\n")
            f.write("[{}]({})".format(title, url))
            f.write("\n\n---\n\n")
            f.write(text)
            f.write("\n\n")
            f.write("## 题解\n\n")
            f.write("### 方法一:\n\n")
            f.write("#### 思路\n\n\n\n")
            f.write("#### 代码\n\n")
            f.write("``` cpp\n\n")
            f.write("```\n")
    return f"{title}.md"

if __name__ == '__main__':
    slug = input("slug:")
    gen_file(slug)