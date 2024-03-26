#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
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


void sol() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n+1), b(n+1), sufb(n+2), f(n+2);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
    }
    for (int i=n; i>=1; i--) {
        sufb[i] = sufb[i+1]+b[i];
    }
    priority_queue<ll, vector<ll>, greater<>> pq;
    pq.emplace(0);
    ll ans = 1e18;
    for (int i=n; i>=1; i--) {
        f[i] = pq.top()+a[i]+sufb[i+1];
        if (i>m) pq.push(f[i]-sufb[i]);
        if (i<=m) {
            ans = min(ans, f[i]);
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