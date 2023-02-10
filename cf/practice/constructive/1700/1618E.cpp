#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n;
    cin >> n;
    vector<ll> b(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    if (accumulate(b.begin(), b.end(), 0LL) % (n * (n + 1) / 2)) {
        cout << "NO\n";
        return;
    }
    ll s = a[0] = accumulate(b.begin(), b.end(), 0LL) / (n * (n + 1) / 2);
    for (int i = 1; i < n; i++) {
        if ((s - b[i] + b[i - 1]) % n) {
            cout << "NO\n";
            return;
        }
        a[i] = (s - b[i] + b[i - 1]) / n;
        a[0] -= a[i];
    }
    for (ll i : a) {
        if (i <= 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (ll i : a) {
        cout << i << " ";
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