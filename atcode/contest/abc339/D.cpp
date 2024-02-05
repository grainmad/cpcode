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

void sol() {
    int n;
    cin >> n;
    vector<string> g(n);
    for (auto& i:g) cin >> i;
    vector<pair<int,int>> p;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (g[i][j] == 'P'){
                p.push_back({i,j});
            }
        }
    }
    int d[n][n][n][n];
    memset(d, -1, sizeof(d));
    d[p[0].first][p[0].second][p[1].first][p[1].second] = 0;
    queue<vector<int>> q;
    q.emplace(vector<int>{p[0].first, p[0].second, p[1].first, p[1].second});
    while (q.size()) {
        auto v = q.front();
        q.pop();
        int x1 = v[0], y1 = v[1], x2 = v[2], y2 = v[3];
        if (x1 == x2 && y1 == y2) {
            cout << d[x1][y1][x2][y2] << "\n";
            return ;
        }
        for (int i=0; i<4; i++) {
            int mx1 = x1+(i-1)%2;
            int my1 = y1+(i-2)%2;
            int mx2 = x2+(i-1)%2;
            int my2 = y2+(i-2)%2;
            if (mx1<0 || mx1>=n || my1<0 || my1>=n || g[mx1][my1]=='#') mx1 = x1, my1 = y1;
            if (mx2<0 || mx2>=n || my2<0 || my2>=n || g[mx2][my2]=='#') mx2 = x2, my2 = y2;
            if (d[mx1][my1][mx2][my2] != -1) continue;
            d[mx1][my1][mx2][my2] = d[x1][y1][x2][y2] + 1;
            q.emplace(vector<int>{mx1, my1, mx2, my2});
        }
    }
    cout << "-1\n";
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
