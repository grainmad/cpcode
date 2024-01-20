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
    string a, b, c;
    cin >> a >> b >> c;
    int ok = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] && a[i] != c[i]) {
            ok = 1;
        }
        if (c[i] != a[i] && c[i] != b[i]) {
            ok = 1;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
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