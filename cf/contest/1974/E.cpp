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

const ll NINF = 0xf3f3f3f3f3f3f3f3;

void sol() {
    ll m, x;
    cin >> m >> x;
    vector<ll> c(m+1), h(m+1);
    for (int i=1; i<=m; i++) {
        cin >> c[i] >> h[i];
    }
    ll mh = *max_element(h.begin()+1, h.end())*m;
    vector<vector<ll>> f(m+1, vector<ll>(mh+1, NINF));
    f[0][0] = 0;
    int ans = 0;
    for (int i=1; i<=m; i++) {
        for (int j=0; j<=mh; j++) {
            f[i][j] = f[i-1][j]+x;
            if (j>=h[i] && f[i-1][j-h[i]]>=c[i]) {
                f[i][j] = max(f[i][j], f[i-1][j-h[i]]-c[i]+x);
            }
            if (f[i][j] >=0) ans = max(ans, j);
        }
    }

    // cout << f << endl;
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