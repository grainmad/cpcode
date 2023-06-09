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
    vector<ll> a(n);
    for (auto& i : a)
        cin >> i;
    sort(a.begin(), a.end());
    // for (int i : a)
    //     cout << i << " ";
    // cout << "\n";
    // for (int i = 1; i < n; i++) {
    //     cout << a[i] - a[i - 1] << " ";
    // }
    // cout << "\n";
    ll l = 0, r = 1e10;
    while (l < r) {
        ll m = l + r >> 1;
        int p = 0, c = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] - a[p] > 2 * m)
                p = i, c++;
        }
        if (c > 3) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << r << "\n";
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