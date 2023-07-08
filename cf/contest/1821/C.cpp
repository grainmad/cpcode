#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = n;
    for (char i = 'a'; i <= 'z'; i++) {
        int mx = 0;
        for (int j = 0; j < n;) {
            int p = j;
            while (p < n && s[p] != i)
                p++;
            mx = max(mx, p - j);
            j = p + 1;
        }
        int tans = 0;
        while (mx) {
            mx /= 2;
            tans++;
        }
        ans = min(ans, tans);
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