// B - 病毒侵袭 HDU - 2896
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define MAXN 100005
#define N 10005
#define SIGMA 94

using namespace std;

bool isvir;
int cnt[505];
char str[N];

int tr[MAXN][SIGMA];
int val[MAXN];
int fail[MAXN];
int last[MAXN];
int sz = 1;

void ac_insert(char* s, int id) {
    int len = strlen(s), u = 0;
    for (int i = 0; i < len; i++) {
        if (tr[u][s[i] - '!'] == 0) {
            tr[u][s[i] - '!'] = sz++;
        }
        u = tr[u][s[i] - '!'];
    }
    val[u] = id;
}

void ac_build() {
    queue<int> que;
    for (int i = 0; i < SIGMA; i++) {
        if (tr[0][i])
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
        for (int j = tr[u][s[i] - '!']; j; j = last[j]) {
            if (val[j]) {
                cnt[val[j]] = 1;
                isvir = true;
            }
        }
        u = tr[u][s[i] - '!'];
    }
}

int main() {
    int n, m, c = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str);
        ac_insert(str, i);
    }
    ac_build();
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        isvir = false;
        memset(cnt, 0, sizeof(cnt));
        scanf("%s", str);
        ac_query(str);
        if (isvir) {
            c++;
            printf("web %d:", i);
            for (int j = 1; j <= n; j++) {
                if (cnt[j])
                    printf(" %d", j);
            }
            printf("\n");
        }
    }
    printf("total: %d\n", c);
    return 0;
}
