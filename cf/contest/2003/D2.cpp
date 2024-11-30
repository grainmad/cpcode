#include <bits/stdc++.h>
// #define SINGLE_INPUT
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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> p;
    map<ll,vector<ll>> g;
    ll mxl = 0, mxr = 0;
    for (int i=0; i<n; i++) {
        int l;
        cin >> l;
        set<ll> st;
        ll mex = 0;
        for (int j=0; j<l; j++) {
            int x;
            cin >> x;
            st.insert(x);
            while (st.count(mex)) mex++;
        }
        ll pmex = mex;
        mxl = max(mxl, mex);
        st.insert(mex);
        while (st.count(mex)) mex++;
        // cout << "mex" << mex << endl;
        mxr = max(mxr, mex);
        g[pmex].push_back(mex);
        p.emplace_back(pmex, mex);
    }
    // cout << p << endl;
    ll ans = max(m-mxr, 0LL)*(mxr+1+m)/2; // sum [mxr+1, m]
    ll lest = 0;
    map<ll,ll> f;
    auto dfs = [&](auto& self, ll x)->ll {
        if (f.count(x)) return f[x];
        f[x] = x;
        for (ll y:g[x]) {
            f[x] = max(f[x], self(self, y));
        }
        return f[x];
    };
    for (int i=mxr; i>=0; i--) {
        dfs(dfs, i);
        if (g[i].size()>=2) {
            for (auto& j:g[i]) {
                lest = max(lest, dfs(dfs, j));
            }
        }
    }
    // cout << format("mxl{} mxr{} lest{}", mxl, mxr, lest) << endl;
    for (int i=0; i<=min(mxr, m); i++) {
        ans += max({mxl, dfs(dfs, i), lest});
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