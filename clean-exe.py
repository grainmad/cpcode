
import os

def dfs(path):
    dir = os.listdir(path)
    for i in dir:
        cur = path+"/"+i
        if os.path.isdir(cur):
            # print(cur, "isdir")
            dfs(cur)
        if os.path.isfile(cur):
            # print(cur, "isfile")
            if cur[-4:] == ".exe":
                os.remove(cur) 

dfs(".")
