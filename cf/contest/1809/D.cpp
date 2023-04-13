#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

const ll coin1 = 1e12, coin2 = 1e12 + 1;

void sol() {
    string s;
    cin >> s;
    int n = s.size();
    int s1 = count(s.begin(), s.end(), '1'), s0 = n - s1;
    int c1 = 0, c0 = 0;
    ll ans = min(s1, s0) * coin2;
    for (int i = 0; i < n - 1; i++) {
        c1 += s[i] == '1';
        c0 += s[i] == '0';
        ans = min(ans, (c1 + s0 - c0) * coin2);
        if (s[i] == '1' && s[i + 1] == '0') {
            ans = min(ans, (c1 + s0 - c0 - 2) * coin2 + coin1);
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