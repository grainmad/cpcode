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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i:a) cin >> i;
    vector<map<pair<int,int>, ll>> mp(3);
    map<tuple<int,int,int>, ll> mp2;
    ll ans = 0;
    for (int i=2; i<n; i++) {
        if (mp[0].count({a[i-2], a[i-1]})) ans += mp[0][{a[i-2], a[i-1]}];
        if (mp[1].count({a[i-2], a[i]})) ans += mp[1][{a[i-2], a[i]}];
        if (mp[2].count({a[i-1], a[i]})) ans += mp[2][{a[i-1], a[i]}];
        mp[0][{a[i-2], a[i-1]}]++;
        mp[1][{a[i-2], a[i]}]++;
        mp[2][{a[i-1], a[i]}]++;
        ans -= 3*mp2[tie(a[i-2], a[i-1], a[i])];
        mp2[tie(a[i-2], a[i-1], a[i])]++;
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