#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll f[2][N];

void sol() {
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        f[0][i] = f[1][i] = 0;
        if (s[i - 1] == '0')
            f[0][i] = f[1][i - 1] + 1;
        else if (s[i - 1] == '1')
            f[1][i] = f[0][i - 1] + 1;
        else
            f[0][i] = f[1][i - 1] + 1, f[1][i] = f[0][i - 1] + 1;
        ans += max(f[0][i], f[1][i]);
        // cout << f[0][i] << " " << f[1][i] << endl;
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