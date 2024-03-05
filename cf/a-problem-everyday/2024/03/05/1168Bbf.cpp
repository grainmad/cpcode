
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
#define INF 0x3f3f3f3f
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
    string s;
    cin >> s;
    // cout << s << endl;
    ll n = s.size();
    vector<ll> d(n, INF);
    for (ll i=0; i<n; i++) {
        for (ll j=1; i-j>=0 && i+j<n; j++) {
            if (s[i-j] == s[i] && s[i] == s[i+j]) {
                d[i] = j;
                break;
            }
        }
    }
    // cout << d << "\n";
    ll ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            for (int k=i; k<=j; k++) {
                if (i<=k-d[k] && d[k]+k<=j) {
                    ans++;
                    break;
                }
            }
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
