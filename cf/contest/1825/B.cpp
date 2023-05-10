#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n * m);
    if (n > m)
        swap(n, m);
    for (ll& i : a)
        cin >> i;
    sort(a.begin(), a.end());
    ll a1 = a[0], a2 = a[1], a3 = a[n * m - 2], a4 = a[n * m - 1];
    cout << max((a4 - a2) * (n - 1) + (a4 - a1) * (m - 1) * n,
                (a3 - a1) * (n - 1) + (a4 - a1) * (m - 1) * n)
         << "\n";
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