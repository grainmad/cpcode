#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll u, v;
    cin >> u >> v;
    if (u == 0 && v == 0) {
        cout << 0 << endl;
    } else if (u == v) {
        cout << 1 << endl;
        cout << u << endl;
    } else if (v > u && (v - u) % 2 == 0) {
        if (u & (v - u) / 2) {
            cout << 3 << endl;
            cout << u << " " << (v - u) / 2 << " " << (v - u) / 2 << endl;
        } else {
            cout << 2 << endl;
            cout << (u ^ (v - u) / 2) << " " << (v - u) / 2 << endl;
        }
    } else {
        cout << "-1" << endl;
    }
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