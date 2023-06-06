
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
#define INF 0x3f3f3f3f
using namespace std;

int d[10];
int bitcnt(int x) {
    int rt = 0;
    for (; x; x = x & (x - 1))
        rt++;
    return rt;
}
int to_dec(string& s) {
    int rt = 0;
    for (int j = 0; j < 7; j++) {
        if (s[j] == '1')
            rt |= 1 << j;
    }
    return rt;
}

void sol() {
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> a(n);  // 可变数字，需要点亮数
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x = to_dec(s);
        for (int j = 0; j < 10; j++) {
            if ((x ^ d[j]) == d[j] - x) {  // d[j] 包含 x
                a[i].emplace_back(j, bitcnt(d[j] - x));
            }
        }
        // for (auto& [i, j] : a[i]) {
        //     cout << "[" << i << " " << j << "]"
        //          << " ";
        // }
        // cout << endl;
    }
    // dp[i][j]
    // 后i个数在恰好用了j次点亮后的能形成最大字典序，且第i个数是dp[i][j]
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
    dp[n][0] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= k; j++) {
            for (auto [u, v] : a[i]) {
                if (j - v >= 0 && dp[i + 1][j - v] != INF)
                    dp[i][j] = u;
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= k; j++) {
    //         cout << i << " " << j << " " << dp[i][j] << endl;
    //     }
    // }
    vector<int> ans;
    int i = 0, j = k;
    while (i < n && j >= 0 && dp[i][j] != INF) {
        ans.push_back(dp[i][j]);
        for (auto [u, v] : a[i]) {
            if (u == dp[i][j]) {
                j -= v;
                i++;
                break;
            }
        }
    }
    if (ans.size() == 0) {
        cout << "-1\n";
        return;
    }
    for (int i : ans) {
        cout << i;
    }
    cout << endl;
}

int main() {
    vector<string> num = {"1110111", "0010010", "1011101", "1011011",
                          "0111010", "1101011", "1101111", "1010010",
                          "1111111", "1111011"};
    for (int i = 0; i < 10; i++) {
        d[i] = to_dec(num[i]);
        // cout << d[i] << " ";
    }
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
