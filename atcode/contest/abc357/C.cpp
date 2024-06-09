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
    int n;
    cin >> n;
    int sz = 1;
    for (int i=0; i<n; i++) sz *= 3;
    vector g(sz, string(sz, '#'));
    function<void(int,int,int)> dfs = [&](int x, int y, int lev) {
        if (lev == 0) return ;
        for (int i=x+lev/3; i<x+lev/3*2; i++) {
            for (int j=y+lev/3; j<y+lev/3*2; j++) {
                g[i][j] = '.';
            }
        }
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (i == 1 && j == 1) continue;
                dfs(x+lev/3*i, y+lev/3*j, lev/3);
            }
        }
    };
    dfs(0,0,sz);
    for (auto i:g) {
        cout << i << "\n";
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