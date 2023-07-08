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
    if (s[0] == '0') {
        cout << "0\n";
        return;
    }
    int ans;
    if (s[0] == '?') {
        ans = 9;
        for (int i = 1; i < n; i++) {
            if (s[i] == '?')
                ans *= 10;
        }
    } else {
        ans = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '?')
                ans *= 10;
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