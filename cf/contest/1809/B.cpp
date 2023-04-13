#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n;
    cin >> n;
    ll l = 0, r = 1e9;
    while (l < r) {
        ll m = (r - l) / 2 + l;
        if ((m + 1) * (m + 1) >= n)
            r = m;
        else
            l = m + 1;
    }
    cout << r << "\n";
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