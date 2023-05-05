
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    string s;
    cin >> n >> s;
    int cr = count(s.begin(), s.end(), 'R');
    if (cr == 0 || cr == n) {
        cout << (n + 2) / 3 << "\n";
    } else {
        while (s.size() && s.back() == s[0])
            s.pop_back();
        s = string(n - s.size(), s[0]) + s;
        int ans = 0, p = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != s[p]) {
                ans += (i - p) / 3;
                p = i;
            }
        }
        ans += (n - p) / 3;
        cout << ans << "\n";
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
