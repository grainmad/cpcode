#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d < b) {
        cout << "-1\n";
        return;
    }
    c -= d - b;
    if (c > a) {
        cout << "-1\n";
        return;
    }
    cout << d - b + a - c << "\n";
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