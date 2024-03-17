#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;
const ll INF = 1e18;

template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p) {
    return os<<'['<<p.first<<", "<<p.second<<']';
}
template<class t> ostream& operator<<(ostream& os,const vector<t>& v) {
    os<<'['; int s = 1;
    for(auto e:v) { if (s) s = 0; else os << ", "; os << e; }
    return os<<']';
}
template<class t,class u> ostream& operator<<(ostream& os,const map<t,u>& mp){
    os<<'{'; int s = 1;
    for(auto [x,y]:mp) { if (s) s = 0; else os << ", "; os<<x<<": "<<y; }
    return os<<'}';
}

void sol() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> g(2*n+1);
    for (int i=0; i<m; i++) {
        ll x, y, w;
        cin >> x >> y >> w;
        g[x].emplace_back(y, w);
        g[y+n].emplace_back(x+n, w);
    }
    for (int i=1; i<=n; i++) {
        g[i].emplace_back(i+n, 0);
    }
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> pq;
    pq.emplace(0,1);
    vector<ll> dis(2*n+1, INF), vis(2*n+1);
    dis[1] = 0;
    while (pq.size()) {
        auto [x, y] = pq.top(); pq.pop();
        if  (vis[y]) continue;
        vis[y] = 1;
        for (auto [u,w]:g[y]) {
            if (dis[u] > dis[y]+w) {
                dis[u] = dis[y]+w;
                pq.emplace(dis[u], u);
            }
        }
    }
    for (int i=n+2; i<=2*n; i++) {
        if (dis[i] == INF) cout << "-1 ";
        else cout << dis[i] << " ";
    }
    cout << "\n";
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