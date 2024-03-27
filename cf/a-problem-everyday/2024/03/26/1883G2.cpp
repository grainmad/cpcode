
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
    vector<ll> a(n-1), b(n);
    for (auto& i:a) cin >> i;
    for (auto& i:b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    auto check = [&](ll s) {
        auto sa = a;
        sa.push_back(s);
        for (int i=n-2; i>=0; i--) {
            if (sa[i] > sa[i+1]) swap(sa[i], sa[i+1]);
        }
        // cout << s << endl;
        // cout << sa << endl;
        // cout << b << endl;
        ll l=0, r=n;
        while (l<r) {
            ll m = l+r>>1;
            int ok = 1;
            for (int i=m; i<n;i++) {
                if (b[i] <= sa[i-m]) ok = 0;
            }
            if (ok) { 
                r = m;
            } else {
                l = m+1;
            }
        }
        return r;
    };
    ll v = check(1);
    ll l=1, r=m+1;
    while (l<r) {
        ll m = l+r>>1;
        if (check(m) != v) r = m;
        else l = m+1;
    }
    cout << v*(r-1) + (m-r+1)*check(r) << '\n';

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
