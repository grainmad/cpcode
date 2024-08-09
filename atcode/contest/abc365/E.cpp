#include <bits/stdc++.h>
#define SINGLE_INPUT
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
    vector<ll> a(n);
    for (ll& i:a) cin >> i;
    ll s = 0;
    for (int i=0; i<31; i++) {
        int c0 = 0, cur = 0, c1 = 0;
        vector<ll> o(2);
        ll cnt = 0;
        for (int j=0; j<n; j++) {
            // cout << i << " " << j << " " << (a[j]>>i&1) << endl;
            int c = a[j]>>i&1;
            c1 += c;
            cur ^= c;
            if (c == 0) c0++;
            else {
                o[cur] += c0+1;
                c0 = 0;
            }
            // cout << o[cur] << " -- \n";
            cnt += o[cur];
        }
        cnt -= c1;
        // cout << cnt << endl;
        s += cnt*(1LL<<i);
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