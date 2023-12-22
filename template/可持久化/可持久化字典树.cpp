// 非递归版
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 600010, len = 23;
int n, m, s[N];
int ch[N * 25][2], ver[N * 25];
int root[N], idx;

void insert(int x, int y, int i) {
    ver[x] = i;
    for (int k = len; k >= 0; k--) {
        int c = s[i] >> k & 1;
        ch[x][!c] = ch[y][!c];
        ch[x][c] = ++idx;
        y = ch[y][c];
        x = ch[x][c];
        ver[x] = i;
    }
}
int query(int x, int L, int v) {
    int res = 0;
    for (int k = len; k >= 0; k--) {
        int c = v >> k & 1;
        if (ver[ch[x][!c]] >= L)
            x = ch[x][!c], res += 1 << k;
        else
            x = ch[x][c];
    }
    return res;
}
int main() {
    int l, r, x, ans;
    char op;
    scanf("%d%d", &n, &m);
    ver[0] = -1;
    root[0] = ++idx;
    insert(root[0], 0, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        root[i] = ++idx;
        s[i] = s[i - 1] ^ x;
        insert(root[i], root[i - 1], i);
    }
    while (m--) {
        scanf(" %c", &op);
        if (op == 'A') {
            scanf("%d", &x);
            root[++n] = ++idx;
            s[n] = s[n - 1] ^ x;
            insert(root[n], root[n - 1], n);
        } else {
            scanf("%d%d%d", &l, &r, &x);
            ans = query(root[r - 1], l - 1, s[n] ^ x);
            printf("%d\n", ans);
        }
    }
    return 0;
}