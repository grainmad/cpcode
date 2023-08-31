#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    vector<int> g[n + 1];
    vector<ll> in(n + 1), mx(n + 1), mn(n + 1, k);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        in[y]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            mx[i] = h[i];
            mn[i] = h[i];
            q.push(i);
        }
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            mn[v] = min(mn[v], mn[u]);
            mx[v] = max(mx[v], mx[u]);
            if (--in[v] == 0) {
                // cout << v << " " << h[v] << endl;
                if (mx[v] % k > h[v]) {
                    mx[v] += k - mx[v] % k + h[v];
                } else {
                    mx[v] += -(mx[v] % k) + h[v];
                }
                q.push(v);
            }
        }
    }
    map<ll, ll> mp;

    auto add = [&](ll left, ll right) {
        for (auto it = mp.lower_bound(left);
             it != mp.end() && it->second <= right; mp.erase(it++)) {
            ll l = it->second, r = it->first;
            left = min(left, l);
            right = max(right, r);
        }
        mp[right] = left;
    };
    for (int i = 1; i <= n; i++) {
        add(mn[i], mx[i]);
    }
    ll l = mp.begin()->second, r = mp.rbegin()->first;
    ll R = (r + k - 1) / k * k;
    ll Mn = r - l;
    vector<pair<ll, ll>> v(mp.begin(), mp.end());
    for (int i = 1; i < v.size(); i++) {
        Mn = min(Mn, R - (v[i].second - v[i - 1].first));
    }
    cout << Mn << "\n";
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