#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 3005
#define MOD 998244353
using namespace std;

struct ST {
    ll st[N][15];  // st[i][j] 代表区间[i, i+2^j)最大值
    void init(const vector<ll>& a) {
        int n = a.size();
        for (int i = 1; i <= n; i++)
            st[i][0] = a[i - 1];
        for (int j = 1; (1 << j) <= n; j++) {              // 区间大小
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {  // 区间下限
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    ll ask(int l, int r) {
        int k = 0;
        while ((1 << (k + 1)) <= r - l + 1)
            k++;
        return min(st[l][k], st[r - (1 << k) + 1][k]);
    }
} s[N];

ll f[N][N];

ll x[N], p[N];

// sum [l,r]
ll S(int l, int r) {
    return p[r] - p[l - 1];
}

void sol() {
    ll n, A, B, C, D;
    cin >> n >> A >> B >> C >> D;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        p[i] += p[i - 1] + x[i];
    }
    for (int len = 1; len <= n; len++) {
        vector<ll> a;
        for (int i = 1, j = len; j <= n; i++, j++) {
            f[i][j] = max(x[j] - f[i][j - 1], x[i] - f[i + 1][j]);
            if (len <= B) {
                f[i][j] = max(f[i][j], S(i, j) - A);
            } else {
                f[i][j] = max(f[i][j], S(i, j) - A - s[len - B].ask(i, i + B));
            }
            if (len <= D) {
                f[i][j] = max(f[i][j], S(i, j) - C);
            } else {
                f[i][j] = max(f[i][j], S(i, j) - C - s[len - D].ask(i, i + D));
            }
            a.push_back(S(i, j) + f[i][j]);
        }
        s[len].init(a);
    }
    cout << f[1][n] << "\n";
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