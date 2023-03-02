#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    string u, v;
    cin >> u >> v;
    if (u[0] == v[0]) {
        cout << "YES\n";
        cout << u[0] << "*\n";
        return;
    }
    if (u.back() == v.back()) {
        cout << "YES\n";
        cout << "*" << u.back() << "\n";
        return;
    }
    for (int i = 1; i < u.size(); i++) {
        for (int j = 1; j < v.size(); j++) {
            if (u[i - 1] == v[j - 1] && u[i] == v[j]) {
                cout << "YES\n";
                cout << "*" << u[i - 1] << u[i] << "*\n";
                return;
            }
        }
    }
    cout << "NO\n";
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