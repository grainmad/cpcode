
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

random_device seed;
ranlux48 engine(seed());
int random(int l, int r) {
    uniform_int_distribution<> distrib(l, r);
    return distrib(engine);
}
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
    vector<pair<int,int>> e;
    vector<vector<int>> g(n+1);
    vector<int> in(n+1);
    for (int i=0; i<m; i++) {
        int d, x, y;
        cin >> d >> x >> y;
        if (d) g[x].emplace_back(y), in[y]++;
        e.emplace_back(x, y);
    }
    // cout << g << endl;
    // cout << v << endl;
    queue<int> q;
    for (int i=1; i<=n; i++) {
        if (!in[i]) {
            q.push(i);
        }
    }
    vector<int> ord(n+1);
    int p = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        ord[u] = p++;
        for (auto v:g[u]) {
            if (--in[v]==0) {
                q.push(v);
            }
        }
    }
    // cout << ord << endl;
    for (int i=1; i<=n; i++) {
        if (in[i]) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
    for (auto [x, y]:e) {
        if (ord[x] < ord[y]) {
            cout << x << " " << y << "\n";
        } else {
            cout << y << " " << x << "\n";
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
