import os
from lxml import etree
import requests

# 转化文档中html标签


def process_txt(txt):
    pass


def get_contest_info(id):
    rt = {}
    url = 'https://codeforces.com/contest/'+id+'/problems'
    head = {
        'Referer': 'https://codeforces.com/',
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36'
    }
    response = requests.get(url, headers=head)
    html = response.text
    # print(html)
    html_element = etree.HTML(html)
    contest_title = html_element.xpath(
        '//*[@id="body"]/div/div[2]/text()')[0]
    # print(contest_title)
    rt["contest_title"] = contest_title
    # //*[@id="body"]/div/div[4] frame
    # //*[@id="body"]/div/div[4]/div[1]/div[2]/div[2]/div statement
    problem_statements = html_element.xpath(
        '//div[@class="problem-statement"]')
    rt["problem_statements"] = []
    for problem_statement in problem_statements:
        header = [item for item in problem_statement.xpath(
            'div[@class="header"]/div//text()')]
        # print(header)
        problem_description = [etree.tostring(i).decode('utf8')
                               for i in problem_statement.xpath('div[2]/*')]
        # print(problem_description)
        input_specification = [etree.tostring(i).decode('utf8')
                               for i in problem_statement.xpath('div[@class="input-specification"]/*')]
        # print(input_specification)
        output_specification = [etree.tostring(i).decode('utf8')
                                for i in problem_statement.xpath('div[@class="output-specification"]/*')]
        # print(output_specification)
        sample_tests = [etree.tostring(i).decode('utf8')
                        for i in problem_statement.xpath('div[@class="sample-tests"]/*')]
        # print(sample_tests)
        note = [etree.tostring(i).decode('utf8')
                for i in problem_statement.xpath('div[@class="note"]/*')]
        # print(note)
        rt['problem_statements'].append(
            {
                "header": {
                    "title": header[0],
                    "tlpt": header[1]+": "+header[2],
                    "mlpt": header[3]+": "+header[4],
                    "stdin": header[5] + ": "+header[6],
                    "stdout": header[7] + ": "+header[8]
                },
                "problem_description": problem_description,
                "input_specification": input_specification,
                "output_specification": output_specification,
                "sample_tests": sample_tests,
                "note": note
            })
    rt['status'] = "ok" if rt['problem_statements'] else "not ok"
    # print(rt)
    return rt


def run():
    id = '1840'
    # id = input("Please enter contets id: ")
    info = get_contest_info(id)

    if info["status"] != "ok":
        print('no such contest!', 'https://codeforces.com/contest/'+id+'/problems')
        return
    dir = 'cf/contest/'+id
    if not os.path.exists(dir):
        os.makedirs(dir)
    src_file = os.listdir(dir)
    # print(src_file)

    def gettxt(path):
        with open(path, 'r', encoding='utf8') as g:
            return g.readlines()

    def update():
        old_txt = gettxt(dir+'/'+id+".md")
        # print("old ", old_txt)
        new_txt = []
        idx = 0
        skip = False
        for i in old_txt:
            if i == '```\n':
                skip = False
            if skip:
                continue
            if idx < len(info['problem_statements']):
                problem_name = info['problem_statements'][idx]['header']['title']
                prefix = problem_name.split(". ")[0]
                if i == '## ['+problem_name+']('+'https://codeforces.com/contest/'+id+'/problem/'+prefix+')\n':
                    idx += 1
            new_txt.append(i)
            if i == '``` cpp\n':
                skip = True
                problem_name = info['problem_statements'][idx -
                                                          1]['header']['title']
                prefix = problem_name.split(". ")[0]
                if prefix + '.cpp' in src_file:
                    new_txt.append(
                        ''.join(gettxt(dir+"/"+prefix+'.cpp')))
                new_txt.append('\n')
        # print("new ", new_txt)
        with open(dir+'/'+id+".md", 'w', encoding='utf8') as f:
            f.writelines(new_txt)

    def create():
        txt = ['# ' + info['contest_title'] + '\n',
               '[Complete problemset](https://codeforces.com/contest/'+id+'/problems)\n\n']
        for problem in info['problem_statements']:
            prefix = problem['header']['title'].split('. ')[0]
            txt += ['## ['+problem['header']['title']+']('+'https://codeforces.com/contest/'+id+'/problem/'+prefix+')\n\n',
                    '### 题意\n\n\n\n',
                    '### 思路\n\n\n\n',
                    '### 代码\n\n',
                    '``` cpp\n',
                    ''.join(gettxt(dir+"/"+prefix+'.cpp')) if prefix +
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
