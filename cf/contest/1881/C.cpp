#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<string> g(n);
    for (auto& i : g)
        cin >> i;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector<int> c(26);
            c[g[i][j] - 'a']++;
            c[g[j][n - i - 1] - 'a']++;
            c[g[n - i - 1][n - j - 1] - 'a']++;
            c[g[n - j - 1][i] - 'a']++;
            int mx = 0;
            for (int i = 0; i < 26; i++) {
                if (c[i])
                    mx = i;
            }
            for (int i = 0; i < mx; i++) {
                if (c[i])
                    ans += (mx - i) * c[i];
            }
        }
    }
    cout << ans / 4 << "\n";
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