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

ll f1[81][81][81][81], f2[81][81][81][81];

/*
    f[i][j][x][y] 从(0,0)到(i,j)所有路径中，经过的最大值为(x,y)的【最少步数，最大钱数】
    f[i][j][x][y] 转移更新 f[i+1][j][x'][y']  f[i][j+1][x'][y']
*/

void sol() {
    int n;
    cin >> n;
    vector<vector<ll>> g(n, vector<ll>(n, 0)), r(n, vector<ll>(n, 0)), d(n, vector<ll>(n, 0));
    for (auto& i:g) {
        for (auto& j:i) {
            cin >> j;
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-1; j++) {
            cin >> r[i][j];
        }
    }
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n; j++) {
            cin >> d[i][j];
        }
    }
    memset(f1, 0x3f, sizeof(f1));
    f1[0][0][0][0] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int x=0; x<=i; x++) {
                for (int y=0; y<=j; y++) {
                    // cout << i << " " << j << " " << x << " " << y << " " << f1[i][j][x][y] << " " << f2[i][j][x][y] << endl;
                    if (i+1<n) {
                        int mx = x, my = y;
                        if (g[i+1][j] > g[x][y]) mx = i+1, my = j;
                        // f[i][j][x][u].second + s*g[i][j] >= d[i][j], s >= ceil(d[i][j]-f[i][j][x][y].second)/g[i][j]
                        ll u = f1[i][j][x][y], v = f2[i][j][x][y];
                        ll& tu = f1[i+1][j][mx][my];
                        ll& tv = f2[i+1][j][mx][my];
                        ll s = (v >= d[i][j] ? 0 : (d[i][j] - v + g[x][y]-1)/g[x][y]);
                        ll s1 = u+s+1, s2 = v+s*g[x][y]-d[i][j];
                        if (tu > s1 || tu == s1 && tv < s2) {
                            tu = s1;
                            tv = s2;
                        }
                    }
                    if (j+1<n) {
                        int mx = x, my = y;
                        if (g[i][j+1] > g[x][y]) mx = i, my = j+1;
                        ll u = f1[i][j][x][y], v = f2[i][j][x][y];
                        ll& tu = f1[i][j+1][mx][my];
                        ll& tv = f2[i][j+1][mx][my];
                        ll s = (v >= r[i][j] ? 0 : (r[i][j] - v + g[x][y]-1)/g[x][y]);
                        ll s1 = u+s+1, s2 = v+s*g[x][y]-r[i][j];
                        if (tu > s1 || tu == s1 && tv < s2) {
                            tu = s1;
                            tv = s2;
                        }
                    }
                }
            }
        }
    }
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ans = min(ans, f1[n-1][n-1][i][j]);
        }
    }
    cout << ans << "\n";

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