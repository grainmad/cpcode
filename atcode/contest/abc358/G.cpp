#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define NINF 0xf3f3f3f3f3f3f3f3
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
    int sx, sy;
    cin >> sx >> sy;
    sx--; sy--;
    vector<vector<ll>> g(n, vector<ll>(m, -1));
    vector f(n, vector(m, vector<ll>(n*m+1, NINF)));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> g[i][j];
        }
    }
    f[sx][sy][0] = 0;
    for (int i=1; i<=n*m; i++) {
        for (int x=0; x<n; x++) {
            for (int y=0; y<m; y++) {
                f[x][y][i] = max(f[x][y][i], f[x][y][i-1]);
                for (int j=0; j<4; j++) {
                    int mx = x+(j-1)%2;
                    int my = y+(j-2)%2;
                    if (mx<0 || mx>=n || my<0 || my>=m) continue;
                    f[x][y][i] = max(f[x][y][i], f[mx][my][i-1]+g[x][y]);
                }
                // cout << x <<" " << y << " "  << i <<" " << f[x][y][i] <<endl;
            }
        }
    }
    
    ll ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int t=0; t<=min(n*m, k); t++) {
                if (f[i][j][t] >= 0)
                    ans = max(ans, f[i][j][t] + (k-t)*g[i][j]);
            }
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