#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

int dp[200005];

void sol() {
    string s;
    cin >> s;
    int sz = s.size();
    string str = "*";
    for (char i : s) {
        str.push_back(i);
        str.push_back('*');
    }
    int n = str.size();
    int r = 0, m = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r)
            dp[i] = min(dp[i - 2 * m], r - i);
        int l = i - dp[i] - 1, r = i + dp[i] + 1;
        while (l >= 0 && r < n && str[l] == str[r]) {
            l--, r++;
            dp[i]++;
        }
        if (dp[i] + i > r) {
            r = dp[i] + i;
            m = i;
        }
    }
    vector<int> span(sz);
    for (int i = 1; i < n; i += 2) {
        span[i / 2] = dp[i] / 2;
    }
    for (int i = 0; i < n; i++) {
        cout << i << ' ' << span[i] << endl;
    }
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