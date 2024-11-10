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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), ps(n+1), lnk(n+1), f(n+1, -1);
    for (auto& i:a) cin >> i;
    for (int i=1; i<=n; i++) ps[i] = ps[i-1] + a[i-1];
    for (int i=0; i<=n; i++) {
        int p = upper_bound(ps.begin(), ps.end(), ps[i]+x)-ps.begin();
        lnk[i] = p;
    }
    function<ll(int)> dfs = [&](int x)->ll {
        if (x > n) return 0;
        if (f[x] != -1) return f[x];
        f[x] = 1;
        return f[x] += dfs(lnk[x]);
    };
    for (int i=0; i<=n; i++) {
        dfs(i);
    }

    // cout << a << endl;
    // cout << lnk << endl;
    // cout << f << endl;
    ll ans = 0;
    for (int i=0; i<n; i++) {
        // cout << n-i-(f[i]-1) << " ";
        ans += n-i-f[i]+1;
    } 
    // cout << endl;
    cout << ans << endl;
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