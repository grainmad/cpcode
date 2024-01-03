import os
from lxml import etree
import requests

# 转化文档中html标签


def process_txts(txts):
    rep_sub = [("<p>", ""), ("</p>", "\n"), ("<li>", "*"), ("</li>", "\n"), ("<ul>", ""), ("</ul>", ""), ('<span class="tex-font-style-bf">', ""), ('<span class="tex-font-style-it">', ""),
               ('<span class="tex-font-style-tt">', ''), ("</span>", ""), ("$$$", "$"), ("&#160;&#8212;", ""), ('<div class="section-title">', "**"), ('</div>', "**\n")]

    def process_txt(txt):
        for i, j in rep_sub:
            txt = txt.replace(i, j)
            txt = txt.strip()
        return txt+"\n\n"

    if isinstance(txts, list):
        return [process_txt(item_txt) for item_txt in txts]
    else:
        return process_txt(txts)

def get_question_meaning(qid):
    url = 'https://www.luogu.com.cn/problem/'+qid
    head = {
        'Referer': 'https://www.lougu.com.cn/',
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36'
    }
    response = requests.get(url, headers=head)
    html = response.text
    if "题目未找到" in html:
        return ""
    # print(html)
    html_element = etree.HTML(html)
    mean = html_element.xpath(
            '//article/div/text()')[0]
    return mean

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
        # print("CF"+id+header[0].split('.')[0])
        rt['problem_statements'].append(
            {
                "header": {
                    "title": header[0],
                    "tlpt": header[1]+": "+header[2],
                    "mlpt": header[3]+": "+header[4],
                    "stdin": header[5] + ": "+header[6],
                    "stdout": header[7] + ": "+header[8]
                },
                "question_meaning": get_question_meaning("CF"+id+header[0].split('.')[0]),
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
    # id = '1840'
    id = input("Please enter contets id: ")
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
        print("old ", old_txt)
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
                problem_name = info['problem_statements'][idx-1]['header']['title']
                prefix = problem_name.split(". ")[0]
                if prefix + '.cpp' in src_file:
                    new_txt.append(
                        ''.join(gettxt(dir+"/"+prefix+'.cpp')))
                new_txt.append('\n')
        print("new ", new_txt)
        with open(dir+'/'+id+".md", 'w', encoding='utf8') as f:
            f.writelines(new_txt)

    def create():
        txt = ['# ' + info['contest_title'] + '\n',
               '[Complete problemset](https://codeforces.com/contest/'+id+'/problems)\n\n']
        for problem in info['problem_statements']:
            prefix = problem['header']['title'].split('. ')[0]
            txt += ['## ['+problem['header']['title']+']('+'https://codeforces.com/contest/'+id+'/problem/'+prefix+')\n\n',
                    '### 题意\n\n',
                    problem['question_meaning']+"\n\n",
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
    # info = get_contest_info("1838")
    # with open('a.md', 'w', encoding='utf8') as f:
    #     for i in info['problem_statements']:
    #         f.writelines(
    #             i['problem_description'])
    #         f.writelines(
    #             i['input_specification'])
    #         f.writelines(
    #             i['output_specification'])
    # f.writelines(process_txts(
    #     i['problem_description']))
    # f.writelines(process_txts(
    #     i['input_specification']))
    # f.writelines(process_txts(
    #     i['output_specification']))

[("<p>", ""), ("</p>", "\n"), ("<li>", ""), ("</li>", "\n"), ("<ul>", ""), ("</ul>", ""), ('<span class="tex-font-style-bf">', ""), ('<span class="tex-font-style-it">', ""),
 ("</span>", ""), ("$$$", "$"), ("&#160;&#8212;", ""), ('<div class="section-title">', "**"), ('</div>', "**\n")]

'''
'contest_title': 'Codeforces Round 878 (Div. 3)', 
'problem_statements': [{'header': {'title': 'A. Cipher Shifer', 'tlpt': 'time limit per test: 1 second', 'mlpt': 'memory limit per test: 256 megabytes', 'stdin': 'input: standard input', 'stdout': 
'output: standard output'}, 
'problem_description': [
    '<p>There is a string $$$a$$$ (unknown to you), consisting of lowercase Latin letters, encrypted according to the following rule into string $$$s$$$:</p>', 
    '<ul> <li> after each character of string $$$a$$$, an arbitrary (possibly zero) number of any lowercase Latin letters, different from the character itself, is added; </li><li> after each such addition, the character that we supplemented is added. </li></ul>', '<p>You are given string $$$s$$$, and you need to output the initial string $$$a$$$. In other words, you need to decrypt string $$$s$$$.</p>', '<p>Note 
that each string encrypted in this way is decrypted <span class="tex-font-style-bf">uniquely</span>.</p>'], 


'problem_description': [
    '<p><span class="tex-font-style-bf">The only difference between easy and hard versions is the maximum number of queries. In this version, you are allowed to ask at most $$$1000$$$ queries.</span></p>',
    '<p><span class="tex-font-style-it">This is an interactive problem.</span></p>',
    '<p>You are playing a game. The circle is divided into $$$n$$$ sectors, sectors are numbered from $$$1$$$ to $$$n$$$ in some order. You are in the adjacent room and do not know either the number of sectors or their numbers. There is also an arrow that initially points to some sector. Initially, the host tells you the number of the sector to which the arrow points. After that, you can ask the host to move the arrow $$$k$$$ sectors counterclockwise or clockwise at most $$$1000$$$ times. And each time you are told the number of the sector to which the arrow points.</p>', 
    '<p>Your task is to determine the integer $$$n$$$&#160;&#8212; the number of sectors in at most $$$1000$$$ queries.</p>', 
    '<p>It is guaranteed that $$$1 \\le n \\le 10^6$$$.</p>'
], 
'input_specification': [
    '<div class="section-title">Input</div>', 
    '<p>The input consists of a single integer $$$x$$$ ($$$1 \\le x \\le n$$$)&#160;&#8212; the number of the initial sector.</p>'
    ], 
'output_specification': [
    '<div class="section-title">Output</div>',
    '<p>After you determine the integer $$$n$$$&#160;&#8212; the number of sectors, you should output "! n" ($$$1 \\le n \\le 10^6$$$). After that the program should immediately terminate.</p>', 
    '<p>Note that, printing the answer does not count as a query.</p>', 
    '<p>It is guaranteed that the integer $$$n$$$ and the numbers of the sectors are fixed initially and will not be changed by the jury program depending on the queries.</p>'
    ], 
'sample_tests': [
    '<div class="section-title">Example</div>', 
    '<div class="sample-test"><div class="input"><div class="title">Input</div><pre>1\n\n5\n\n6\n\n7\n\n2\n\n10\n\n9\n\n8\n\n4\n\n3\n\n1</pre></div><div class="output"><div class="title">Output</div><pre>+ 1\n\n+ 1\n\n+ 1\n\n+ 1\n\n+ 1\n\n+ 1\n\n+ 1\n\n+ 1\n\n+ 1\n\n+ 1\n\n! 10</pre></div></div>'
    ], 
'note': [
    '<div class="section-title">Note</div>', 
    '<p><span class="tex-font-style-bf">Hacks</span></p>', 
    '<p>To hack, use the following test format.</p>', 
    '<p>In the first line, output a single integer $$$n$$$ ($$$1 \\le n \\le 10^6$$$)&#160;&#8212; the number of sectors.</p>', 
    '<p>In the second line, output $$$n$$$ different integers $$$1 \\le a_1, a_2, \\dots, a_n \\le n$$$&#160;&#8212; the numbers of the sectors in clockwise order, the arrow initially points to the sector with the number $$$a_1$$$.</p>'
    ]
'''
