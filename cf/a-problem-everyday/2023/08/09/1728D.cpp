
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

// 反向获取
void sol() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(
        n, vector<int>(n, -2));  // 面对s[l...r]，a是否会赢。-1a，0d，1b
    auto cmp = [](char x, char y) {
        if (x < y)
            return -1;
        if (x > y)
            return 1;
        return 0;
    };
    auto dfs = [&](auto self, int l, int r) {
        if (l > r)
            return 0;
        if (dp[l][r] != -2)
            return dp[l][r];
        int d1 = self(self, l + 2, r), d2 = self(self, l + 1, r - 1),
            d3 = self(self, l, r - 2);
        int c1 = cmp(s[l], s[l + 1]), c2 = cmp(s[l], s[r]),
            c3 = cmp(s[r], s[l]), c4 = cmp(s[r], s[r - 1]);
        c1 = d1 ? d1 : c1;
        c2 = d2 ? d2 : c2;
        c3 = d2 ? d2 : c3;
        c4 = d3 ? d3 : c4;
        return dp[l][r] = min(max(c1, c2), max(c3, c4));
    };
    int rt = dfs(dfs, 0, n - 1);
    if (rt == -1) {
        cout << "Alice\n";
    } else if (rt == 1) {
        cout << "Bob\n";
    } else {
        cout << "Draw\n";
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
