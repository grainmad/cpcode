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
    if (n == 1) {
        cout << "1\n";
        return;
    }
    sort(a.begin(), a.end());
    ll gc = a[1] - a[0];
    for (int i = 1; i < n; i++) {
        gc = gcd(gc, a[i] - a[0]);
    }
    ll ans = 0, add = 1;
    for (int i = n - 1; i >= 0; i--) {
        ll d = (a[n - 1] - a[i]) / gc;
        ans += d;
        if (add && d != n - 1 - i) {
            ans += n - 1 - i;
            add = 0;
        }
    }
    if (add)
        ans += (a[n - 1] - a[0]) / gc + 1;
    cout << ans << "\n";
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