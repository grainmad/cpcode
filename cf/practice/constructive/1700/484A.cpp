#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll a, b;
    cin >> a >> b;
    for (int i = 62; i >= 0; i--) {
        if (!(a >> i & 1) && (b >> i & 1)) {
            ll t = b | ((1LL << i) - 1);
            if (t <= b)
                cout << t << "\n";
            else
                cout << (t ^ (1LL << i)) << "\n";
            return;
        }
    }
    cout << a << "\n";
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