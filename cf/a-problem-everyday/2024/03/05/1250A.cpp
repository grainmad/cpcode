
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), mp(n), mx(n), mn(n);
    iota(a.begin(), a.end(), 0);
    iota(mp.begin(), mp.end(), 0);
    iota(mx.begin(), mx.end(), 0);
    iota(mn.begin(), mn.end(), 0);
    for (int i=0; i<m; i++) {
        int x;
        cin >> x;
        x--;
        if (mp[x] != 0) {
            int p1 = mp[x]-1, p2 = mp[x];
            int v1 = a[mp[x]-1], v2 = a[mp[x]];
            swap(a[p1], a[p2]);
            mp[v2] = p1;
            mp[v1] = p2;
            mn[v2] = min(mn[v2], mp[v2]);
            mx[v1] = max(mx[v1], mp[v1]);
        }
    }
    for (int i=0; i<n; i++) {
        cout << mn[i]+1 << " " << mx[i]+1 << "\n";
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
