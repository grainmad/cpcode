#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define MAXN 1000005
#define SIGMA 26
using namespace std;
/*
1. 建立字典树
2. 生成fail指针和字典图
*/

struct Ac {
    int tr[MAXN][SIGMA];
    int val[MAXN];  // 关键字节点 val[i] i号节点是编号为val[i]的模式串，从1开始
    int fail[MAXN];  // 指向最长的后缀且是前缀树的前缀
    int last[MAXN];  // 在fail链中指向离自己最近的关键字节点
    int cnt[MAXN];   // cnt[i] 编号为i的模式串出现的次数数
    int sz;          // 节点个数
    int id;          // 为将插入的模式串分配的id
    Ac() {
        memset(tr, 0, sizeof(tr));
        memset(val, 0, sizeof(val));
        memset(fail, 0, sizeof(fail));
        sz = 1;
        id = 1;
    }
    // 插入
    void insert(char* s) {
        int len = strlen(s), u = 0;
        for (int i = 0; i < len; i++) {
            if (tr[u][s[i] - 'a'] == 0) {
                tr[u][s[i] - 'a'] = sz++;
            }
            u = tr[u][s[i] - 'a'];
        }
        val[u] = id++;
    }
    // 建立fail指针和字典图 优化：在建立fail后再建立last
    void build() {
        queue<int> que;
        for (int i = 0; i < SIGMA; i++) {
            if (tr[0][i])
                que.push(tr[0][i]);
        }
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int i = 0; i < SIGMA; i++) {
                if (tr[u][i]) {  // 存在
                    fail[tr[u][i]] = tr[fail[u]][i];
                    last[tr[u][i]] = val[fail[tr[u][i]]]
                                         ? fail[tr[u][i]]
                                         : last[fail[tr[u][i]]];  // 优化
                    que.push(tr[u][i]);
                } else {
                    tr[u][i] = tr[fail[u]][i];
                }
            }
        }
    }
    // 查询, 每个节点都要暴力跳fial指针直到根节点， 期间可能有单词节点
    void query(char* s) {
        int u = 0;
        for (int i = 0, len = strlen(s); i < len; i++) {
            for (int j = tr[u][s[i] - 'a']; j; j = fail[j]) {
                if (val[j] != 0) {  // j是单词节点
                    cnt[val[j]]++;
                    printf(
                        "编号为%d的模式串最后一个字符出现在文本串下标%d位置\n",
                        val[j], i);
                }
            }
            u = tr[u][s[i] - 'a'];
        }
    }
    // 优化查询
    void queryWithLast(char* s) {
        int u = 0;
        for (int i = 0, len = strlen(s); i < len; i++) {
            for (int j = tr[u][s[i] - 'a']; j; j = last[j]) {
                if (val[j] != 0) {  // j是单词节点
                    cnt[val[j]]++;
                    printf(
                        "编号为%d的模式串最后一个字符出现在文本串下标%d位置\n",
                        val[j], i);
                }
            }
            u = tr[u][s[i] - 'a'];
        }
    }
    // 打印每个字符串出现次数
    void print() {
        printf("每个模式串出现的次数\n");
        for (int i = 1; i < id; i++) {
            printf("%d %d\n", i, cnt[i]);
        }
    }
    // debug
    void debug() {
        for (int i = 0; i < sz; i++) {
            printf("fail[%d]=%d\n", i, fail[i]);
        }
        for (int i = 0; i < sz; i++) {
            printf("last[%d]=%d\n", i, last[i]);
        }
    }
};

char txt[100];
// char pat[5][100] = {"i", "she", "his", "hers", "he"};
char pat[8][100] = {"abc",     "aabc", "aaabc", "aaaabc",
                    "aaaaabc", "ab",   "aaab",  "aaaaab"};

int main() {
    Ac ac;
    for (int i = 0; i < 8; i++) {
        ac.insert(pat[i]);
        cout << i + 1 << " " << pat[i] << endl;
    }
    ac.build();
    while (1) {
        cin >> txt;
        ac.queryWithLast(txt);
        ac.print();
        ac.debug();
        memset(ac.cnt, 0, sizeof(Ac::cnt));
    }
    return 0;
}
