
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

#define MAXN 200005
int st[MAXN][20];  // st[i][j] 代表区间[i, i+2^j)最小值

void ST(const vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++)
        st[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++) {             // 区间大小
        for (int i = 0; i + (1 << j) - 1 < n; i++) {  // 区间下限
            st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int ask(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1)
        k++;
    return __gcd(st[l][k], st[r - (1 << k) + 1][k]);
}

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    ST(a);
    int p = 0;
    vector<int> ans(n, 0);
    while (p < n) {
        int l = p, r = n;
        while (l < r) {
            int m = l + r >> 1;
            if (ask(p, m) > m - p + 1) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (r != n && ask(p, r) == r - p + 1) {
            ans[r] = 1;
            p = r + 1;
        } else {
            p++;
        }
    }
    for (int i = 0, pre = 0; i < n; i++) {
        pre += ans[i];
        cout << pre << " ";
    }
    cout << "\n";
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
