#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    unordered_map<int, int> mp[26];
    int mask = (1 << 26) - 1;
    ll ans = 0;
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int u = 0;
        vector<int> c(26);
        for (char j : s) {
            u ^= 1 << j - 'a';
            c[j - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            if (c[j] == 0) {
                mp[j][u | (1 << j)]++;
                ans += mp[j][(u ^ mask) | (1 << j)];
            }
        }
    }
    cout << ans << "\n";
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