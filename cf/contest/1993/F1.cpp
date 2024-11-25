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
    int n, k, w, h;
    cin >> n >> k >> w >> h;
    string s;
    cin >> s;
    map<pair<ll,ll>,ll> c;
    ll x=0, y=0;
    for (char i:s) {
        if (i == 'U') y++;
        if (i == 'D') y--;
        if (i == 'R') x++;
        if (i == 'L') x--;
        x = (x + 2*w)%(2*w);
        y = (y + 2*h)%(2*h);
        c[{x,y}]++;
    }
    ll ans = 0;
    for (int i=0; i<k; i++) {
        ans += c[{(2*w-i*x%(2*w))%(2*w),(2*h-i*y%(2*h))%(2*h)}];
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