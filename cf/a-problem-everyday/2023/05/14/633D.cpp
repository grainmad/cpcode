
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll& i : a)
        cin >> i;
    map<ll, int> mp;
    for (ll i : a)
        mp[i]++;
    int ans = 2;
    if (mp.count(0))
        ans = max(ans, mp[0]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || a[i] == 0 && a[j] == 0)
                continue;
            int cnt = 2;
            map<ll, int> c;
            ll p = a[i], q = a[j];
            c[p]++;
            c[q]++;
            while (mp.count(p + q) && ++c[p + q] <= mp[p + q]) {
                int t = p + q;
                p = q;
                q = t;
                cnt++;
            }
            ans = max(ans, cnt);
        }
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
