#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, k;
    cin >> n >> k;
    int mask = (1 << k) - 1;
    map<int, ll> mp;
    mp[0]++;
    int p = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p ^= x;
        if (mp.count(p))
            mp[p]++;
        else
            mp[p ^ mask]++;
    }
    ll ans = n * (n + 1) / 2;
    for (auto [i, j] : mp) {
        ll a = j / 2, b = j - a;
        ans -= a * (a - 1) / 2 + b * (b - 1) / 2;
    }
    cout << ans << "\n";
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