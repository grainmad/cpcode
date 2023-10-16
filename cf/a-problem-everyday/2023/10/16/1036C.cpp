
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

string s;
ll dp[20][4][2][2];
ll dfs(int p, int c, int limit, int zero) {
    if (p == s.size()) return 1;
    if (dp[p][c][limit][zero] != -1) return dp[p][c][limit][zero]; //遇到计算过的状态直接返回
    ll res = 0;
    if (zero == 1) res += dfs(p+1, 0, 0, 1);

    for (int i=(zero?1:0); i<=(limit?s[p]-'0':9); i++) {
        if (i != 0 && c == 3) continue;
        res += dfs(p+1, c+(i != 0), limit&&(i==s[p]-'0'), 0);
    }
    return dp[p][c][limit][zero] = res;
}
ll countSpecialNumbers(ll n) {
    s = to_string(n);
    memset(dp, -1, sizeof(dp));
    return dfs(0, 0, 1, 1);
}

void sol() {
    ll l, r;
    cin >> l >> r;
    ll a = countSpecialNumbers(r);
    ll b = countSpecialNumbers(l-1);
    // cout << a << " " << b << endl;
    cout << a-b << "\n";
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
