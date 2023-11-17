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
    vector<int> a(n);
    for (int& i : a)
        cin >> i;
    vector<int> dp(n);
    dp[0] = a[0];
    int ans = a[0];
    for (int i = 1; i < n; i++) {
        if ((a[i - 1] - a[i]) % 2 == 0)
            dp[i] = a[i];
        else
            dp[i] = max(dp[i - 1], 0) + a[i];
        ans = max(ans, dp[i]);
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