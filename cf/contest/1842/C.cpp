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
    vector<int> c(n + 1, -1), f(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        f[i] = f[i - 1];
        if (c[x] != -1)
            f[i] = max({f[i], f[c[x]] + i - c[x], f[c[x] - 1] + i - c[x] + 1});
        c[x] = i;
        // cout << f[i] << " ";
    }
    cout << f[n] << "\n";
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