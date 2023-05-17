
import datetime
import os
import json
from git.repo import Repo


if __name__ == "__main__":
    # Mount directory as hexo blog
    with open('hexo-deployer-setting.json', 'r', encoding='utf8') as f:
        setting = json.load(f)
    repo_path = setting["repo_path"]
    blog_path = repo_path+"/source/_posts"
    mount_dirs = ["leetcode", "cf/a-problem-everyday", "cf/contest"]

    repo = Repo(repo_path)
    repo.git.pull("--rebase")

    blog_list = os.listdir(blog_path)
    # print(blog_list)

    def gen_blog(path):
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

        file_path = blog_path+"/"+sp[-1]
        new_file = []
        new_file.append("---\n")
        new_file.append("title: "+sp[-1][:-3]+"\n")
        new_file.append("date: "+get_datetime(file_path)+"\n")
        new_file.append(
            "updated: " + datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S') + "\n")
        new_file.append("tag:\n")
        for i in sp[:-1]:
            new_file.append("- "+i+"\n")
        new_file.append("categories: "+sp[0]+"\n")
        new_file.append("mathjax: true\n")
        new_file.append("comments: true\n")
        ds = ["description:"]
        for i in sp[:-1]:
            ds.append(" "+i)
        ds.append("\n")
        new_file.append(''.join(ds))
        new_file.append("author: lxc\n")
        new_file.append("---\n")
        with open(path, "r", encoding="utf8") as g:
            new_file += g.readlines()

        if sp[-1] in blog_list:  # 已存在同名文件，除更新无差别，则不用更改
            cp_file = new_file.copy()
            del (cp_file[3])
            with open(file_path, 'r', encoding="utf8") as f:
                txt = f.readlines()
                if len(txt) > 3:
                    del (txt[3])
                # print(txt)
                # print(cp_file)
                if txt == cp_file:
                    print("not modified", file_path)
                    return

        with open(file_path, 'w', encoding="utf8") as f:
            f.writelines(new_file)
        print("generate success", file_path)

    def dfs(path):
        dir = os.listdir(path)
        for i in dir:
            cur = path+"/"+i
            if os.path.isdir(cur):
                dfs(cur)
            if os.path.isfile(cur):
                # print(cur)
                if cur[-3:] == '.md':
                    gen_blog(cur)

    for mount_dir in mount_dirs:
        dfs(mount_dir)

    repo.git.add("--all")
    repo.git.commit("-m auto update by hexo-deployer")
    repo.git.push()
