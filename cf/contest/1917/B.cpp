#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> c(256), d(n);
    int cnt = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (c[s[i]]++ == 0)
            cnt++;
        d[i] = cnt;
        ans += d[i];
        // cout << d[i] << ", ";
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