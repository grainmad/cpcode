
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll& i : v)
        cin >> i;
    // if (n<=3) {
    //     cout << "0\n";
    //     for (ll i:v) cout << i << " ";
    //     cout << "\n";
    // }
    sort(v.begin(), v.end());

    double l = 0, r = v[n - 1] - v[0];
    while (r - l >= 1e-7) {
        double m = (r - l) / 2 + l;
        int p = 0, c = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] - v[p] > m)
                p = i, c++;
        }
        if (c < 3) {
            r = m;
        } else {
            l = m;
        }
    }
    cout.precision(6);
    cout << fixed << r / 2 << "\n";
    int p = 0, c = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] - v[p] > r) {
            cout << (v[i - 1] + v[p]) / 2.0 << " ";
            c++;
            p = i;
        }
    }
    for (int i = c; i < 3; i++) {
        cout << (v[n - 1] + v[p]) / 2.0 << " ";
    }
    cout << "\n";
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
