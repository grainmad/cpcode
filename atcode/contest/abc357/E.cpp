#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
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
    int n;
    cin >> n;
    vector<ll> in(n), to(n), vis(n), val(n, -1);
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        x--;
        in[x]++;
        to[i] = x;
    }
    // cout << to << endl;
    queue<ll> q;
    for (int i=0; i<n; i++) {
        if (in[i] == 0) {
            q.push(i);
            vis[i] = 1;
        }
    }
    // cout << vis << endl;
    while (q.size()) {
        ll u = q.front();
        q.pop();
        u = to[u];
        if (--in[u] == 0) {
            q.push(u);
            vis[u] = 1;
        }
    }
    // cout << vis << endl;
    for (int i=0; i<n; i++) {
        if (vis[i] || val[i] != -1) continue;
        ll cnt = 1;
        int u = to[i];
        while (u != i) {
            cnt++;
            u = to[u];
        }
        val[i] = cnt;
        u = to[i];
        while (u != i) {
            val[u] = cnt;
            u = to[u];
        }
    }
    // cout << val << endl;
    function<ll(int)> dfs = [&](int x) {
        if (val[x] != -1) return val[x];
        return val[x] = dfs(to[x])+1;
    };
    for (int i=0; i<n; i++) dfs(i);
    // cout << val << endl;
    cout << accumulate(val.begin(), val.end(), 0LL) << "\n";
    
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