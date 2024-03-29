
#include <bits/stdc++.h>
#define SINGLE_INPUT
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
    for(auto e:v) { if (s) s = 0; else os << ", "; os << e; }
    return os<<']';
}
template<class t,class u> ostream& operator<<(ostream& os,const map<t,u>& mp){
    os<<'{'; int s = 1;
    for(auto [x,y]:mp) { if (s) s = 0; else os << ", "; os<<x<<": "<<y; }
    return os<<'}';
}

struct Edge {
    int x, y, w;
    Edge(int x, int y, int w):x(x),y(y),w(w){}
    bool operator<(const Edge& o) const {
        return w < o.w;
    }
};

void sol() {
    int n, q;
    cin >> n >> q;
    vector<int> fa(n+1, -1);
    function<int(int)> ufind = [&](int x) {
        return fa[x] < 0 ? x : fa[x] = ufind(fa[x]);
    };
    vector<Edge> edge;
    for (int i=1; i<n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edge.emplace_back(x, y, w);
    }
    sort(edge.begin(), edge.end());
    vector<ll> qr(q), idx(q), ans(q, 0);
    for (auto& i:qr) cin >> i;
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](ll a, ll b) {
        return qr[a] < qr[b];
    });
    auto cpt = [&](ll x)->ll {
        return x*(x-1)/2;
    };
    // cout << qr << endl;
    // cout << idx << endl;
    ll cur = 0;
    int p = 0;
    for (int i:idx) {
        while (p<n-1 && edge[p].w <= qr[i]) {
            int x = edge[p].x, y = edge[p].y;
            int fx = ufind(x), fy = ufind(y);
            cur -= cpt(-fa[fx]);
            cur -= cpt(-fa[fy]);
            fa[fx] += fa[fy];
            fa[fy] = fx;
            cur += cpt(-fa[fx]);
            p++;
        }
        ans[i] = cur;
    }
    for (auto i:ans) {
        cout << i << " ";
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
