
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
    // cout << string(2, '#');
    string d = "ULDR";
    int n;
    cin >> n;
    vector<string> g(n+1, string(n+1, '#'));
    vector<vector<pair<int,int>>> p(n+1, vector<pair<int,int>>(n+1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> p[i][j].first >> p[i][j].second;
        }
    }
    vector<vector<int>> vis(n+1, vector<int>(n+1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            auto [x, y] = p[i][j];
            if (x == i && j == y) {
                g[i][j] = 'X';
                // cout << "xx " << i << " " << j << endl;
                queue<pair<int,int>> q;
                q.emplace(i,j);
                vis[i][j] = 1;
                while (q.size()) {
                    auto [u,v] = q.front(); q.pop();
                    // cout << u << " " << v << endl;
                    for (int c=0; c<4; c++) {
                        int mu = u+(c-1)%2;
                        int mv = v+(c-2)%2;
                        if (0<mu && mu <= n && 0<mv && mv <= n && vis[mu][mv] == 0 && p[mu][mv] == pair<int,int>{i,j}) {
                            vis[mu][mv] = 1;
                            g[mu][mv] = d[(c+2)%4];
                            q.emplace(mu,mv);
                        }
                    }
                    
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (g[i][j] == '#' && p[i][j].first != -1) {
                cout << "INVALID\n";
                return ;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (g[i][j] == '#') {
                queue<pair<int,int>> q;
                for (int c=0; c<4; c++) {
                    int x = i, y = j;
                    int mx = x+(c-1)%2;
                    int my = y+(c-2)%2;
                    if (mx<=0 || mx>n || my<=0 || my>n || g[mx][my] != '#') continue;
                    vis[x][y] = 1;
                    vis[mx][my] = 1;
                    g[x][y] = d[c];
                    g[mx][my] = d[(c+2)%4];
                    q.emplace(x, y);
                    q.emplace(mx, my);
                    break;
                }
                if (q.empty()) {
                    cout << "INVALID\n";
                    return ;
                }
                while (q.size()) {
                    auto [x, y] = q.front(); q.pop();
                    for (int i=0; i<4; i++) {
                        int mx = x+(i-1)%2;
                        int my = y+(i-2)%2;
                        if (mx<=0 || mx>n || my<=0 || my>n || g[mx][my] != '#') continue;
                        g[mx][my] = d[(i+2)%4];
                        vis[mx][my] = 1;
                        q.emplace(mx, my);
                    }
                }
            }
        }
    }
    // cout << vis << endl;
    // cout << g << endl;
    cout << "VALID\n";
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << g[i][j];
        }
        cout << "\n";
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
