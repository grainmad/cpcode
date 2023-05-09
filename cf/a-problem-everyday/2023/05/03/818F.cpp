
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll n;

// 选x个点组成完全子图，共有x(x-1)/2条边，
// n-x个点形成链连接到这个完全子图，存在n-x条桥，所以完全子图中只能保留最多n-x条边

ll f(ll x) {
    return min(x * (x - 1) / 2, n - x) + n - x;
}

void sol() {
    cin >> n;
    // 至少选一个，至多选n个
    ll l = 1, r = n, lans = f(1), rans = f(n);
    while (l < r) {
        ll lmid = l + (r - l) / 3;  // l + 1/3区间大小
        ll rmid = r - (r - l) / 3;  // r - 1/3区间大小
        lans = f(lmid), rans = f(rmid);

        // 求凸函数的极大值
        if (lans <= rans)
            l = lmid + 1;
        else
            r = rmid - 1;
    }
    // 求凸函数的极大值
    cout << max(lans, rans) << endl;
}
int main() {
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
