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
    int n, k;
    cin >> n >> k;
    vector<int> a(2*n);
    for (auto& i:a) cin >> i;
    vector<int> c(n+1);
    for (int i=0; i<n; i++) {
        c[a[i]]++;
    }
    // cout << c << endl;
    int p = 0;
    vector<int> l, r;
    for (int i=1; i<=n; i++) {
        if (l.size() == 2*k) continue;
        if (c[i] == 2) {
            l.push_back(i);
            l.push_back(i);
        }
    }
    for (int i=1; i<=n; i++) {
        if (r.size() == 2*k) continue;
        if (c[i] == 0) {
            r.push_back(i);
            r.push_back(i);
        }
    }
    for (int i=1; i<=n; i++) {
        if (l.size() == 2*k) continue;
        if (c[i] == 1) {
            l.push_back(i);
            r.push_back(i);
        }
    }
    for (int i:l) {
        cout << i << " ";
    } cout << "\n";
    for (int i:r) {
        cout << i << " ";
    } cout << "\n";
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