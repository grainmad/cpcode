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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& i:a) cin >> i;
    int c1 = 1;
    for (int i=0; i<n; i++) {
        if (a[i] > 1) c1 = 0;
        if (a[i] == 1 && c1 == 0) {
            cout << "-1\n";
            return ;
        }
    }
    // cout << a << endl;
    vector<ll> cq(n);
    ll ans = 0;
    for (int i=1; i<n; i++) {
        if (a[i-1] > a[i]) {
            ll t = a[i], c = 0;
            while (a[i-1] > t) t *= t, c++;
            cq[i] += cq[i-1] + c;
        } else if (a[i-1] != 1) {
            ll t = a[i-1], c = 0;
            while (t<=a[i]) t*=t, c++;
            if (c<=cq[i-1]) cq[i] += cq[i-1]-c+1;
        }
        // cout << i << " " << cq[i] << endl;
    }
    // cout << cq << endl;
    for (int i=0; i<n; i++) {
        ans += cq[i];
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