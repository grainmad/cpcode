#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll x, y, n;
    cin >> n >> x >> y;
    if (x > y)
        swap(x, y);
    cout << max(1LL, min(x + y - n + 1, n)) << " "
         << (n - y >= x - 1 ? x + y - 1 : n) << "\n";
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