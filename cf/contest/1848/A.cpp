#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m, k;
    cin >> n >> m >> k;
    int a, b;
    cin >> a >> b;
    int ok = 1;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        if ((abs(a - x) + abs(b - y)) % 2 == 0) {
            ok = 0;
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