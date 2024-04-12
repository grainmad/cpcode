
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
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
    ll n, m, k;
    cin >> n >> m >> k;
    // cout << n << " " << m << " " << k << endl;
    int sz1 = n%m*(n/m+1), sz2 = (m-n%m)*(n/m);
    vector<int> a(sz1), b(sz2);
    iota(a.begin(), a.end(), 0);
    iota(b.begin(), b.end(), sz1);
    // cout << sz1 << " " << sz2 << "\n";
    // cout << a << " " << b << endl;
    auto pr = [&]() {
        for (int i=0; i<sz1; i++) {
            if (i%(n/m+1) == 0) {
                cout << n/m+1;
            }
            cout << " " << a[i]+1;
            if (i%(n/m+1) == n/m) {
                cout << "\n";
            }
        }
        for (int i=0; i<sz2; i++) {
            if (i%(n/m) == 0) {
                cout << n/m;
            }
            cout << " " << b[i]+1;
            if (i%(n/m) == n/m-1) {
                cout << "\n";
            }
        }
    };
    pr();
    ll p = 0;
    while (--k) {
        if (a.size())
        for (int i=0; i<sz2; i++) {
            swap(a[(p+i)%sz1], b[i]);
        }
        p += sz2;
        pr();
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
