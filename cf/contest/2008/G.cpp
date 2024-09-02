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
    ll n, k;
    cin >> n >> k;
    ll g = 0, n0 = 0;
    vector<int> a(n);
    for (auto& i:a) {
        cin >> i;
        if (i == 0) continue;
        n0++;
        g = gcd(g, i);
    }
    // cout << a << " " << g << " " << n0 << endl;
    vector<ll> v;
    if (n0 == n) {
        if (n == 1) {
            v.push_back(a[0]);
        } else {
            // 0 g 2g .. (n-1)g n>1
            for (ll i=0; i<=(n-1)*g; i+=g) {
                v.push_back(i);
            }
        }
    } else {
        if (n0 == 0) {
            v.push_back(0);
        } else {
            // 0 g 2g .. n0g
            for (ll i=0; i<=n0*g; i+=g) {
                v.push_back(i);
            }
        }
    }
    // cout << v << endl;
    ll l = 0, r = 1e12;
    while (l<r) {
        ll m = l+r>>1;
        ll cnt = m+1;
        for (auto i:v) {
            if (i<=m) cnt--;
        }
        if (cnt >= k) {
            r = m;
        } else {
            l = m+1;
        }
    }
    cout << r << "\n";

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