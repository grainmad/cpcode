#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    map<char, int> mp;
    for (int i = 0, j = 1; i < 5; i++, j *= 10) {
        mp['A' + i] = j;
    }
    string s;
    cin >> s;
    int n = s.size();
    string suf(n + 1, '0');
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = max(suf[i + 1], s[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << i << ": " << suf[i] << "\n";
    }
    vector<vector<int>> pre(n + 1, vector<int>(5, 0));
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        pre[i][s[i - 1] - 'A']++;
        cout << i << ": ";
        for (int j = 0; j < 5; j++) {
            cout << pre[i][j] << " ";
        }
        cout << "\n";
    }
    vector<vector<int>> p(n + 1, vector<int>(5));
    vector<int> w(5);
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1];
        p[i][s[i - 1] - 'A'] = w[s[i - 1] - 'A'];
        w[s[i - 1] - 'A'] = i;
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] < suf[i + 1])
            sum -= mp[s[i]];
        else
            sum += mp[s[i]];
    }
    cout << "sum " << sum << "\n";
    ll ans = sum;
    for (int i = 0; i < n; i++) {
        for (char j = 'A'; j <= 'E'; j++) {
            ll delt = 0;
            // self
            if (s[i] < suf[i + 1]) {
                delt += mp[s[i]];
            } else {
                delt -= mp[s[i]];
            }
            if (j < suf[i + 1]) {
                delt -= mp[j];
            } else {
                delt += mp[j];
            }
            cout << i << " " << j << " " << delt << "\n";
            for (char k = max(j, suf[i + 1]); k < suf[i]; k++) {
                delt += 2 * (pre[i][k] - pre[p[i][j - 'A']][k]) * mp[k];
            }
            for (char k = suf[i]; k < max(j, suf[i + 1]); k++) {
                delt -= 2 * (pre[i][k] - pre[p[i][j - 'A']][k]) * mp[k];
            }
            cout << i << " " << j << " " << delt << "\n";
            ans = max(ans, sum + delt);
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