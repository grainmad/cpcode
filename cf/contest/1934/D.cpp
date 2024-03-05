#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
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
    ll n, m;
    cin >> n >> m;
    if ((m ^ n) <= n) {
        cout << "1\n" << n << " " << m << "\n";
        return;
    }

    ll v = n, h1 = 0, h2 = -1;
    while (v) {
        h1++;
        v >>= 1;
    }
    for (ll i = h1 - 2; i >= 0; i--) {
        if (n >> i & 1) {
            h2 = i;
            break;
        }
    }
    // cout << h1 << " " <<  h2 << "\n";
    if (h2 == -1 || ((1LL << h2 + 1) - 1) < m) {
        cout << "-1\n";
    } else {
        cout << "2\n" << n << " " << ((1LL << h2 + 1) - 1) << " " << m << "\n";
    }
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