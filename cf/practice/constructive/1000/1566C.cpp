#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

void sol() {
    int n;
    cin >> n;
    string u, v;
    cin >> u >> v;
    vector<int> num(n + 1), dp(n + 1);
    for (int i = 0; i < n; i++) {
        num[i + 1] = u[i] + v[i] - 2 * '0';
    }
    for (int i = 1; i <= n; i++) {
        if (num[i] == 1)
            dp[i] = dp[i - 1] + 2;
        else if (num[i] == 2) {
            if (i > 1 && num[i - 1] == 0)
                dp[i] = max(dp[i - 1], dp[i - 2] + 2);
            else
                dp[i] = dp[i - 1];
        } else {
            if (i > 1 && num[i - 1] == 2)
                dp[i] = max(dp[i - 1] + 1, dp[i - 2] + 2);
            else
                dp[i] = dp[i - 1] + 1;
        }
    }
    cout << dp[n] << endl;
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