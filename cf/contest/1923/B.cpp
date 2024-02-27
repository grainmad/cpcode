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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), x(n);
    for (auto& i : a)
        cin >> i;
    for (auto& i : x)
        cin >> i, i = abs(i);
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int u, int v) { return x[u] < x[v]; });
    int p = 0;
    for (int stp = 1;; stp++) {
        ll r = k;
        while (p < n && r >= a[idx[p]]) {
            r -= a[idx[p]];
            p++;
        }
        if (p == n) {
            cout << "yes\n";
            return;
        }
        // cout << p << " " << stp << endl;
        // cout << "xx" << x[idx[p]] << " " << stp << endl;
        a[idx[p]] -= r;
        if (x[idx[p]] - stp <= 0) {
            cout << "no\n";
            return;
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