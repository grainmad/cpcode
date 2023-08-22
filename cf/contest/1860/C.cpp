#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll BIT[N];
// ll xBIT[N];

void bit_add(int x, ll val) {
    for (int i = x; i < N; i += i & -i) {
        BIT[i] += val;
        // xBIT[i] += x*val;
        // 区间查询时 BIT[i] += val; xBIT[i] += x*val;
    }
}

ll bit_ps(int x) {
    ll rt = 0;
    for (int i = x; i > 0; i -= i & -i) {
        rt += BIT[i];
        // rt += x*BIT[i]-xBIT[i];
        // 区间查询时 rt += (x+1)*BIT[i]-xBIT[i];
    }
    return rt;
}

void sol() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        BIT[i] = 0;
    }
    int ans = 0, mn = n + 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mn = min(mn, x);
        if (mn != x && bit_ps(x) == 0) {
            bit_add(x, 1);
            ans++;
        }
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