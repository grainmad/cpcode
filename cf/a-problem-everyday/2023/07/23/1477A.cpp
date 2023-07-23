
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& i : a)
        cin >> i;
    sort(a.begin(), a.end());
    ll g = 0;
    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i] - a[i - 1]);
    };
    if ((k - a[0]) % g == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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
