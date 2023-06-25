
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll g = 0;
    for (auto& i : a)
        cin >> i, g = __gcd(g, i);
    cout << "YES\n";
    if (g > 1) {
        cout << "0\n";
    } else {
        int ans = 0;
        for (int i = 0, p; i < n; i++) {
            p = i;
            while (i < n && a[i] % 2)
                i++;
            ans += (i - p) / 2 + (i - p) % 2 * 2;
        }
        cout << ans << "\n";
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
