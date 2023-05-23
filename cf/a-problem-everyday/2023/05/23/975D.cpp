
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, a, b;
    cin >> n >> a >> b;
    map<pair<ll, ll>, ll> mp;
    for (int i = 0; i < n; i++) {
        ll x, vx, vy;
        cin >> x >> vx >> vy;
        mp[{vx, vy}]++;
    }
    map<ll, ll> cnt;
    ll ans = 0;
    for (auto [i, j] : mp) {
        ans += 2 * cnt[a * i.first - i.second] * j;
        cnt[a * i.first - i.second] += j;
    }
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
