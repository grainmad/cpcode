#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

template <class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
    return os << '[' << p.first << ", " << p.second << ']';
}
template <class t>
ostream& operator<<(ostream& os, const vector<t>& v) {
    os << '[';
    int s = 1;
    for (auto e : v) {
        if (s)
            s = 0;
        else
            os << ", ";
        os << e;
    }
    return os << ']';
}
template <class t, class u>
ostream& operator<<(ostream& os, const map<t, u>& mp) {
    os << '{';
    int s = 1;
    for (auto [x, y] : mp) {
        if (s)
            s = 0;
        else
            os << ", ";
        os << x << ": " << y;
    }
    return os << '}';
}

struct Node {
    ll l, d, k, c, a, b;
};

void sol() {
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<Node>());
    for (int i = 1; i <= m; i++) {
        int l, d, k, c, a, b;
        cin >> l >> d >> k >> c >> a >> b;
        g[b].push_back({l, d, k, c, a, b});
    }
    priority_queue<pair<ll, int>> q;
    vector<int> vis(n + 1);
    vector<ll> f(n + 1);
    q.emplace(f[n] = 2e18, n);
    while (q.size()) {
        auto [x, y] = q.top();
        q.pop();
        if (vis[y])
            continue;
        vis[y] = 1;
        for (auto [l, d, k, c, a, b] : g[y]) {
            // l+td+c < x => t = (x-c-l)/d
            ll t = min(k - 1, (x - c - l) / d);
            if (l + t * d > f[a])
                q.emplace(f[a] = l + t * d, a);
        }
    }
    for (int i = 1; i < n; i++) {
        if (f[i] == 0) {
            cout << "Unreachable\n";
        } else {
            cout << f[i] << "\n";
        }
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