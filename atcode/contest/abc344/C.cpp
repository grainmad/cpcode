#include <bits/stdc++.h>
#define SINGLE_INPUT
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
    int n, m, l;
    cin >> n;
    vector<ll> a(n);
    for (auto& i:a) cin >> i;
    cin >> m;
    vector<ll> b(m);
    for (auto& i:b) cin >> i;
    cin >> l;
    vector<ll> c(l);
    for (auto& i:c) cin >> i;
    vector<ll> d;
    for (ll i:a) {
        for (ll j:b) {
            for (ll k:c) {
                d.push_back(i+j+k);
            }
        }
    }
    sort(d.begin(), d.end());
    int q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        int p = lower_bound(d.begin(), d.end(), x)-d.begin();
        if (p != d.size() && d[p] == x) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
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