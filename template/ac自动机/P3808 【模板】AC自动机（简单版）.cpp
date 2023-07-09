// P3808 【模板】AC自动机（简单版）
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define MAXN 1000005
#define SIGMA 26
using namespace std;

int ans = 0;

int tr[MAXN][SIGMA];
int val[MAXN];
int fail[MAXN];
int last[MAXN];
int sz;
void ac_init() {
    memset(tr, 0, sizeof(tr));
    memset(val, 0, sizeof(val));
    memset(fail, 0, sizeof(fail));
    memset(last, 0, sizeof(last));
    sz = 1;
}

void ac_insert(char* s) {
    int len = strlen(s), u = 0;
    for (int i = 0; i < len; i++) {
        if (tr[u][s[i] - 'a'] == 0) {
            tr[u][s[i] - 'a'] = sz++;
        }
        u = tr[u][s[i] - 'a'];
    }
    val[u]++;
}

void ac_build() {
    queue<int> que;
    for (int i = 0; i < SIGMA; i++) {
        if (tr[0][i] != 0)
            que.push(tr[0][i]);
    }
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int i = 0; i < SIGMA; i++) {
            if (tr[u][i]) {
                fail[tr[u][i]] = tr[fail[u]][i];
                last[tr[u][i]] =
                    val[fail[tr[u][i]]] ? fail[tr[u][i]] : last[fail[tr[u][i]]];
                que.push(tr[u][i]);
            } else {
                tr[u][i] = tr[fail[u]][i];
            }
        }
    }
}

void ac_query(char* s) {
    int len = strlen(s), u = 0;
    for (int i = 0; i < len; i++) {
        for (int j = tr[u][s[i] - 'a']; j; j = last[j]) {
            if (val[j]) {
                ans += val[j];
                val[j] = 0;
            }
        }
        u = tr[u][s[i] - 'a'];
    }
}

void debug() {
    for (int i = 0; i < sz; i++) {
        printf("val[%d]=%d\n", i, val[i]);
    }
    for (int i = 0; i < sz; i++) {
        printf("fail[%d]=%d\n", i, fail[i]);
    }
    for (int i = 0; i < sz; i++) {
        printf("last[%d]=%d\n", i, last[i]);
    }
}

char str[MAXN];

int main() {
    ac_init();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        ac_insert(str);
    }
    ac_build();
    //	debug();
    scanf("%s", str);
    ac_query(str);
    printf("%d\n", ans);
    return 0;
}
