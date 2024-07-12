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
template<class t> ostream& operator<<(ostream& os,const set<t>& v) {
    os<<'['; int s = 1;
    for(auto e:v) { if (s) s = 0; else os << ", "; os << e; }
    return os<<']';
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

ll mysqrt(ll x) {
    ll sq = sqrt(x);
    while (sq*sq > x) sq--;
    while ((sq+1)*(sq+1) <= x) sq++;
    return sq;
}


void sol() {
    // get all a^b<=n, b>=3
    ll n;
    cin >> n;
    set<ll> st;
    st.insert(1);
    for (ll i=2; i*i*i<=n; i++) {
        ll t = i*i*i;
        while (1) {
            st.insert(t);
            if (t > n/i) break;
            t*=i;
        }
    }
    // cout << st << endl;
    ll ans = st.size()+mysqrt(n);
    for (ll i:st) {
        ll sq = mysqrt(i);
        if (sq*sq == i) {
            ans--;
        }
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