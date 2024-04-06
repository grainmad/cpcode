
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p) {
    return os<<'['<<p.first<<", "<<p.second<<']';
}
template<class t> ostream& operator<<(ostream& os,const vector<t>& v) {
    os<<'['; int s = 1;
    for(auto e:v) { if (s) s = 0; else os << ", \n"; os << e; }
    return os<<']';
}
template<class t,class u> ostream& operator<<(ostream& os,const map<t,u>& mp){
    os<<'{'; int s = 1;
    for(auto [x,y]:mp) { if (s) s = 0; else os << ", "; os<<x<<": "<<y; }
    return os<<'}';
}

const ll INF = 0x3f3f3f3f3f3f3f3f;

struct Value {
    ll s, m;
    Value(ll s=INF, ll m=0):s(s), m(m) {}
    bool operator<(const Value& o) const {
        if (o.s == s) return m < o.m;
        return s > o.s;
    }
    bool operator!=(const Value& o) const {
        return m != o.m || s != o.s;
    }
};
ostream& operator<<(ostream& os, const Value& v) {
    os<<'['; 
    auto [s, m] = v;
    os << s << ", " << m;
    return os<<']';
}

struct Node {
    int p, mp;
    Value v;
    Node(int p, int mp, Value v): p(p), mp(mp), v(v) {}
    bool operator<(const Node& o) const {
        return v < o.v;
    }
};

void sol() {
    ll n, m, p;
    cin >> n >> m >> p;
    vector<ll> w(n+1);
    for (int i=1; i<=n; i++) {
        cin >> w[i];
    }
    vector<vector<pair<ll,ll>>> g(n+1);
    for (int i=0; i<m; i++) {
        ll a, b, s;
        cin >> a >> b >> s;
        g[a].emplace_back(b, s);
    }
    vector<vector<Value>> f(n+1, vector<Value>(n+1));
    f[1][1] = {0, p};
    priority_queue<Node> pq;
    pq.emplace(1, 1, f[1][1]);
    while (pq.size()) {
        auto c = pq.top(); pq.pop();
        auto [a, b, s] = c;
        // if (s != f[a][b]) continue;
        for (auto& [u, v]:g[a]) {
            int y = w[b] > w[u] ? b:u;
            auto [s1, m1] = s;
            ll k = (max(v-m1, 0LL)+w[b]-1)/w[b];
            Value t(s1+k, m1+k*w[b]-v);
            // cout << u << " " << v << " " << t << endl;
            if (f[u][y] < t) {
                f[u][y] = t;
                pq.emplace(u, y, t);
            }
        }
    }
    // cout << f << endl;
    ll ans = INF;
    for (int i=1; i<=n; i++) {
        ans = min(ans, f[n][i].s);
    }
    if (ans == INF) cout << "-1\n";
    else cout << ans << "\n";
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