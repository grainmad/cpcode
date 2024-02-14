
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005

const ll MOD  = 1e9+7;
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
	string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<int> p(n+1);
    for (int i=m; i<=n; i++) {
        if (s.substr(i-m, m) == t) p[i] = 1;
    }
    vector<ll> f(n+1, MOD), c(n+1);
    f[0] = 0; c[0] = 1;
    for (int i=1; i<=n; i++) {
        if (p[i]) {
            for (int j=i-m+1; j<=i; j++) {
                if (p[j]) f[i] = min(f[i], f[j-m]+1);
            }
            for (int j=i-m+1; j<=i; j++) {
                if (p[j] && f[j-m]+1 == f[i]) c[i] = (c[i] + c[j-m]) % MOD;
            }
        } else {
            f[i] = f[i-1];
            c[i] = c[i-1];
        }
    }
    cout << f[n]%MOD << " " << c[n] << "\n";
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
