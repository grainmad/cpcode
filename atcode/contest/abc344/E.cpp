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

int val[N];
int L[N], R[N];
int sz;
map<int,int> mp;

void add(int x, int y) {
    mp[y] = ++sz;
    int ix = mp[x], iy = sz, iz = R[ix];
    val[iy] = y;
    L[iy] = ix;
    R[iy] = iz;
    R[ix] = iy;
    L[iz] = iy;
}


void del(int x) {
    int ix = mp[x];
    int lix = L[ix], rix = R[ix];
    R[lix] = rix;
    L[rix] = lix;
    L[ix] = R[ix] = 0;
    val[ix] = 0;
    mp.erase(x);
}

void sol() {
    int n;
    cin >> n;
    int p = 0; 
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        add(p, x);
        p = x;
    }
    int q;
    cin >> q;
    while (q--) {
        int opt, x, y;
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y;
            add(x, y);
        } else if (opt == 2) {
            cin >> x;
            del(x);
        }
    }
    int u = R[0];
    while (u) {
        cout << val[u] << " ";
        u = R[u];
    }
    cout << "\n";
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