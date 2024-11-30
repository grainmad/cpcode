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
    int n, m;
    cin >> n >> m;
    vector<int> f(n+1), d(n+2);
    vector<pair<int,int>> p(m);
    for (auto& [x, y]:p) {
        cin >> x >> y;
    }
    sort(p.begin(), p.end(), [&](auto& x, auto& y) {
        return x.second < y.second;
    });
    int id = 0;
    for (int i=2; i<=n; i++) {
        f[i] = f[i-1] + 1;
        while (id<m && p[id].second == i) {
            f[i] = min(f[i], f[p[id].first]+1);
            id++;
        }
    }
    // cout << f << endl;
    id = 0;
    for (int i=1; i<=n; i++) {
        while (id<m && p[id].second == i) {
            auto [l, r] = p[id];
            // stp f[l]+1
            // no win (l, r-f[l]-1)
            if (l+1 < r-f[l]-1) {
                d[l+1]++;
                d[r-f[l]-1]--;
            }
            id++;
        }
    }
    int ps = 0;
    for (int i=1; i<n; i++) {
        ps += d[i];
        cout << (ps?"0":"1");
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