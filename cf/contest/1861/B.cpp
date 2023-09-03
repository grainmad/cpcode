#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    string u, v;
    cin >> u >> v;
    int n = u.size();
    if (u[0] != v[0] || u.back() != v.back()) {
        cout << "NO\n";
        return;
    }
    char l = u[0], r = u.back();
    for (int i = 1; i < n; i++) {
        if (u[i - 1] == v[i - 1] && u[i - 1] == l && u[i] == v[i] &&
            u[i] == r) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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