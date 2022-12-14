#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;


#define MAXN 100005
#define SIGMA 26

int tr[MAXN][SIGMA];
int val[MAXN];
int fail[MAXN];
int last[MAXN];
int sz;

void ac_init() {
    memset(tr, 0, sizeof(tr));
    memset(val, 0, sizeof(val));
    memset(fail, 0, sizeof(fail));
    sz = 1;
}

void ac_insert(char* s, int id) {
    int len = strlen(s), u = 0;
    for (int i=0; i<len; i++) {
        if (tr[u][s[i]-'a'] == 0) {
            tr[u][s[i]-'a'] = sz++;
        }
        u = tr[u][s[i]-'a'];
    }
    val[u] = id;
}

void ac_build() {
    queue<int> que;
    for (int i=0; i<SIGMA; i++) {
        if (tr[0][i]) que.push(tr[0][i]);
    }
    while (!que.empty()) {
        int u = que.front(); que.pop();
        for (int i=0; i<SIGMA; i++) {
            if (tr[u][i]) {
                fail[tr[u][i]] = tr[fail[u]][i];
                last[tr[u][i]] = val[fail[tr[u][i]]]?fail[tr[u][i]]:last[fail[tr[u][i]]];
                que.push(tr[u][i]);
            } else {
                tr[u][i] = tr[fail[u]][i];
            }
        }
    }
}

void ac_query(char* s) {
    int len = strlen(s), u = 0;
    for (int i=0; i<len; i++) {
        for (int j=tr[u][s[i]-'a']; j; j=last[j]) {
            if (val[j]) {
                // printf("partten id: %d last character in text index: %d\n", val[j], i);
                printf("编号为%d的模式串最后一个字符出现在文本串下标%d位置\n", val[j], i); 
            }
        }
        u = tr[u][s[i]-'a'];
    }
}

char s[10000];
char pat[8][100] = {
"abc",
"aabc",
"aaabc",
"aaaabc",
"aaaaabc",
"ab",
"aaab",
"aaaaab"
};

int main() {
    ac_init();
    for (int i=0; i<8; i++) {
        ac_insert(pat[i], i+1);
    }
    ac_build();
    cin >> s;
    ac_query(s);
    return 0;
}