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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& i:a) cin >> i;
    if (k>=n) {
        sort(a.begin(), a.end());
        cout << a[(n-1)/2] << "\n";
        return ;
    }
    // cout << a << endl;
    ll l = 0, r = 1e9+7;
    while (l<r) {
        ll m = l+r>>1;
        vector<ll> f(k, -1e9);
        for (int i=0; i<n; i++) {
            f[i%k] = max(f[i%k], (i%k?f[i%k-1]:0) + (a[i]>=m?1:-1));
        }
        if (f[(n-1)%k] > 0) {
            l = m+1;
        } else {
            r = m;
        }
    }
    cout << r-1 << "\n";
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