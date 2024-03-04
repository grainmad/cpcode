
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

void sol() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll& i:a) cin >> i;
    ll ans = 0;
    for (int i=0; i+1<n; i+=2) {
        ll res = a[i]-a[i+1];
        ans += min(a[i+1], a[i]);
        if (res < 0) continue;
        ll req = 0; 
        for (int j=i+3; j<n; j+=2) {
            req -= a[j-1] - a[j];
            if (req >= 0) {
                ans += min(res, req)+1;
                res -= req;
                req = 0;
            }
            if (res<0) break;
        }
        // cout << i << " " << ans << endl;
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
