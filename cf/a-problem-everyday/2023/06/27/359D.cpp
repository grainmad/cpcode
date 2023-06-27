
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

#define MAXN 300005
int st[MAXN][20];    // st[i][j] 代表区间[i, i+2^j)最小值
int st_g[MAXN][20];  // st_g[i][j] 代表区间[i, i+2^j)gcd

void ST(const vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++)
        st[i][0] = st_g[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++) {             // 区间大小
        for (int i = 0; i + (1 << j) - 1 < n; i++) {  // 区间下限
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            st_g[i][j] = __gcd(st_g[i][j - 1], st_g[i + (1 << (j - 1))][j - 1]);
        }
    }
}

bool ask(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1)
        k++;
    return min(st[l][k], st[r - (1 << k) + 1][k]) ==
           __gcd(st_g[l][k], st_g[r - (1 << k) + 1][k]);
}

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a)
        cin >> i;
    ST(a);
    int l = 1, r = n + 1;
    while (l < r) {
        int m = l + r >> 1;
        int ok = 0;
        for (int i = m - 1; i < n; i++) {
            int j = i - m + 1;  // [j, i]
            if (ask(j, i)) {
                ok = 1;
                break;
            }
        }
        if (ok) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    int sz = r - 1;
    vector<int> ans;
    for (int i = sz - 1; i < n; i++) {
        int j = i - sz + 1;  // [j, i]
        if (ask(j, i))
            ans.push_back(j);
    }
    cout << ans.size() << " " << sz - 1 << "\n";
    for (auto i : ans) {
        cout << i + 1 << " ";
    }
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
