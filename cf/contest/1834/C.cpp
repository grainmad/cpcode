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
    string u, v;
    cin >> u >> v;
    int ans = 2 * n;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        c1 += u[i] != v[i];
    }
    ans = min(ans, c1 * 2 - c1 % 2);
    for (int i = 0; i < n; i++) {
        c2 += u[i] != v[n - 1 - i];
    }
    if (c2 == 0)
        ans = min(ans, 2);
    else
        ans = min(ans, c2 * 2 - (c2 % 2 == 0));
    // cout << c1 << " " << c2 << "\n";
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