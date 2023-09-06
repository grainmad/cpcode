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
    vector<ll> in(n + 1), cnt(n + 1), t(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        in[y]++;
    }
    ll mxt = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            t[i] = h[i];
            q.push(i);
        }
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        mxt = max(mxt, t[u]);
        for (int v : g[u]) {
            if (h[v] >= t[u] % k) {
                t[v] = max(t[v], t[u] - t[u] % k + h[v]);
            } else {
                t[v] = max(t[v], t[u] + k - t[u] % k + h[v]);
            }

            if (in[v] == ++cnt[v]) {
                q.push(v);
            }
        }
    }
    map<ll, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            mp[t[i]].push_back(i);
        }
    }
    auto udp = [&](int x) {
        queue<int> q;
        q.push(x);
        while (q.size()) {
            int u = q.front();
            q.pop();
            mxt = max(mxt, t[u]);
            for (int v : g[u]) {
                if (t[v] < t[u]) {
                    t[v] += k;
                    q.push(v);
                }
            }
        }
    };
    ll ans = 1e18;
    for (auto& [i, j] : mp) {
        ans = min(ans, mxt - i);
        for (int u : j) {
            t[u] += k;
            udp(u);
        }
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