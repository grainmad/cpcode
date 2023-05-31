#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    string s;
    cin >> n >> s;
    int p = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[p] != s[i]) {
            ans = max(ans, i - p);
            p = i;
        }
    }

    ans = max(ans, n - p);
    cout << ans + 1 << "\n";
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