#include <bits/stdc++.h>
#define SINGLE_INPUT
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
    int n, m, l;
    cin >> n >> m >> l;
    int sz = n+m+l;
    vector<pair<int,int>> p(sz);
    for (int i=0; i<sz; i++) {
        cin >> p[i].first;
        p[i].second = i<n?0:(i<n+m?1:2);
    }
    sort(p.begin(), p.end());
    // cout << p << endl;
    int start = 0;
    vector<int> bv(sz);
    for (int i=0; i<sz; i++) {
        bv[i] = p[i].first;
        start |= p[i].second<<2*i;
    }
    map<int,int> f;
    auto dfs = [&](auto& self, int msk) {
        if (f.count(msk)) return f[msk];
        int who = msk>>sz*2; // who = 1, aoki
        for (int i=0; i<sz; i++) {
            int type1 = msk>>i*2&3;
            if (type1 != who) continue;
            for (int j=0; j<sz; j++) {
                int type2 = msk>>j*2&3;
                if (type2 != 2) continue;
                int tmsk = msk^(type1<<2*i)^(type2<<2*i)^(1<<2*sz); // 不拿桌上的牌
                if (bv[j] < bv[i]) { // 能拿就拿
                    tmsk ^= (type2<<2*j)^(type1<<2*j);
                }
                if (!self(self, tmsk)) return f[msk] = 1;
            }
        }
        return f[msk] = 0;
    };
    cout << (dfs(dfs, start)?"Takahashi\n":"Aoki\n");

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