

import argparse
import os
from lxml import etree
import requests

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

def get_contest_info(id):
    url = 'https://atcoder.jp/contests/'+id+'/tasks'
    head = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36'
    }
    response = requests.get(url, headers=head)
    html = response.text
    # print(html)
    html_element = etree.HTML(html)
    title = html_element.xpath(
        '//*[@id="navbar-collapse"]/ul[1]/li/a/text()')[0]
    prefix = html_element.xpath(
        '//*[@id="main-container"]/div[1]/div[2]/div/table/tbody//td[1]/a/text()')
    ptitle = html_element.xpath(
        '//*[@id="main-container"]/div[1]/div[2]/div/table/tbody//td[2]/a/text()')
    link = html_element.xpath(
        '//*[@id="main-container"]/div[1]/div[2]/div/table/tbody//td[2]/a/@href')
    # print(list(zip(prefix, title, link)))
    meaning = [get_question_meaning("AT_"+i.split('/')[-1]) for i in link]
    # print(meaning)
    return title, [(i, i+' - '+j, 'https://atcoder.jp'+k, l) for i, j, k, l in zip(prefix, ptitle, link, meaning)]


# print(get_contest_info('abc303'))


def run():
    # id = 'abc339'
    id = input("Please enter contets id: ")
    title, info = get_contest_info(id)
    # print(title, info)
    if not info:
        print('no such contest!', 'https://atcoder.jp/contests/'+id+'/tasks')
        return
    dir = 'atcode/contest/'+id
    if not os.path.exists(dir):
        os.makedirs(dir)
    src_file = os.listdir(dir)
    # print(src_file)

    def gettxt(path):
        with open(path, 'r', encoding='utf8') as g:
            return g.readlines()

    def update():
        old_txt = gettxt(dir+'/'+id+".md")
        # print(old_txt)
        new_txt = []
        idx = 0
        skip = False
        for i in old_txt:
            if i == '```\n':
                skip = False
            if skip:
                continue
            if idx < len(info) and i == '## ['+info[idx][1]+']('+info[idx][2]+')\n':
                idx += 1
            new_txt.append(i)
            if i == '``` cpp\n':
                skip = True
                # print(''.join(gettxt(dir+"/"+info[idx-1][0]+'.cpp')))
                if info[idx-1][0] + '.cpp' in src_file:
                    new_txt.append(
                        ''.join(gettxt(dir+"/"+info[idx-1][0]+'.cpp')))
                new_txt.append('\n')

        with open(dir+'/'+id+".md", 'w', encoding='utf8') as f:
            f.writelines(new_txt)

    def create():
        txt = ['# ' + title + '\n',
               '[Complete problemset](https://atcoder.jp/contests/'+id+'/tasks)\n\n']
        for i, j, k,l in info:
            txt += ['## ['+j+']('+k+')\n\n',
                    '### 题意\n\n',
                    l,
                    '\n\n',
                    '### 思路\n\n\n\n',
                    '### 代码\n\n',
                    '``` cpp\n',
                    ''.join(gettxt(dir+"/"+i+'.cpp')) if i +
                    '.cpp' in src_file else '\n',
                    '\n```\n',
                    '\n']

        with open(dir+'/'+id+".md", 'w', encoding='utf8') as f:
            f.writelines(txt)

    if id+'.md' in src_file:
        update()  # 存在则更新代码
    else:
        create()  # 不存在则创建文件


if __name__ == "__main__":
    run()
