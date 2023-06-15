#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
using namespace std;

#define MAXN 705
#define SIGMA 2
/*
1. 建立字典树
2. 生成fail指针和字典图
*/

struct Ac {
    int tr[MAXN][SIGMA];
    int val[MAXN];  // 关键字节点 val[i] i号节点是编号为val[i]的模式串，从1开始
    int fail[MAXN];  // 指向最长的后缀且是前缀树的前缀
    int last[MAXN];  // 在fail链中指向离自己最近的关键字节点
    int sz;          // 节点个数
    Ac() {
        memset(tr, 0, sizeof(tr));
        memset(val, 0, sizeof(val));
        memset(fail, 0, sizeof(fail));
        sz = 1;
    }
    // 插入
    void insert(string& s) {
        int len = s.size(), u = 0;
        for (int i = 0; i < len; i++) {
            if (tr[u][s[i] - 'a'] == 0) {
                tr[u][s[i] - 'a'] = sz++;
            }
            u = tr[u][s[i] - 'a'];
        }
        val[u] = 1;
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
            val[u] |= val[fail[u]];
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
} ac;

#define N 505
#define MOD 998244353

struct Matrix {
    int mat[N][N];
    int n;
    Matrix(int n) : n(n) { memset(mat, 0, sizeof(mat)); }
    inline void operator*=(const Matrix& o) {
        int ans[n][n] = {};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j])
                    for (int k = 0; k < n; k++)
                        ans[i][k] =
                            (ans[i][k] + (long long)(mat[i][j]) * o.mat[j][k]) %
                            MOD;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                mat[i][j] = ans[i][j];
    }
    void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
};
/*
    // a *= (b^n)
    for (; n; n >>= 1, b *= b)
        if (n & 1)
            a *= b;
    a.print();
*/

void sol() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        ac.insert(s);
    }
    ac.build();
    int sz = ac.sz;
    Matrix a(sz), b(sz);
    for (int i = 0; i < sz; i++) {
        if (!ac.val[i])
            for (int j = 0; j < SIGMA; j++) {
                ++b.mat[i][ac.tr[i][j]];
            }
    }
    a.mat[0][0] = 1;
    for (; n; n >>= 1, b *= b) {
        if (n & 1)
            a *= b;
    }
    ll ans = 0;
    for (int i = 0; i < sz; i++) {
        if (!ac.val[i])
            ans += a.mat[0][i], ans %= MOD;
    }
    cout << ans << "\n";
}

int main() {
    cout << setprecision(15) << fixed;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef SINGLE_INPUT
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
#else
    sol();
#endif
    return 0;
}