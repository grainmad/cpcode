#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 300005
#define MOD 998244353
using namespace std;

int a[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 2)
            a[i] = -a[i];
    }
    map<ll, int> mp;
    mp[0] = 1;
    ll ans = 0;
    for (ll i = 0, p = 0; i < n; i++) {
        p += a[i];
        if (mp.count(p))
            ans += mp[p];
        mp[p]++;
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