
import os

suffix = [
    'exe',
    # 'txt'
]


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
            if cur.split('.')[-1] in suffix:
                os.remove(cur)


dfs(".")
