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


vector<ll> opt(const vector<ll>& a) {
    int n = a.size();
    vector<ll> cnt(n+1), b(n);
    ll mx = 0;
    for (int i=0; i<n; i++) {
        if (++cnt[a[i]] >= 2) {
            mx = max(mx, a[i]);
        }
        b[i] = mx;
    }
    // cout << b << endl;
    return b;
}

void sol() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll& i:a) cin >> i;
    ll s = accumulate(a.begin(), a.end(), 0LL);
    a = opt(a);
    s += accumulate(a.begin(), a.end(), 0LL);
    a = opt(a);
    for (int i=0; i<n; i++) {
        s += 1LL*a[i]*(n-i);
    }
    
    cout << s << "\n";

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