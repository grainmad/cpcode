import os
from lxml import etree
import requests

id = 'CF1917D'
url = 'https://www.luogu.com.cn/problem/'+id
head = {
    'Referer': 'https://www.lougu.com.cn/',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36'
}
response = requests.get(url, headers=head)
html = response.text
print(html)
if "题目未找到" in html:
    print("no")
html_element = etree.HTML(html)
mean = html_element.xpath(
        '//article/div/text()')[0]
print(mean)
