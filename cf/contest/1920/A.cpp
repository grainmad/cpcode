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
    vector<ll> a;
    ll l = 0, r = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        if (x == 1)
            l = max(l, y);
        if (x == 2)
            r = min(r, y);
        if (x == 3)
            a.push_back(y);
    }
    if (l > r) {
        cout << "0\n";
        return;
    }
    sort(a.begin(), a.end());
    cout << (r - l + 1) - (upper_bound(a.begin(), a.end(), r) -
                           lower_bound(a.begin(), a.end(), l))
         << "\n";
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