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
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for (auto& i : g)
        cin >> i;
    int n;
    cin >> n;
    vector<vector<int>> E(h, vector<int>(w));
    vector<vector<int>> vis(h, vector<int>(w));
    vector<vector<int>> vis2(h, vector<int>(w));
    // cout << E << endl;
    int sx, sy;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (g[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }
    auto sp = [&](int x, int y, int stp, int tag) {
        queue<pair<int, int>> q;
        q.emplace(x, y);
        vis[x][y] = tag;
        while (q.size() && stp > 0) {
            int sz = q.size();
            for (int c = 0; c < sz; c++) {
                auto [x, y] = q.front();
                // cout << x << " " << y << endl;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int mx = x + (i - 1) % 2;
                    int my = y + (i - 2) % 2;
                    if (mx < 0 || mx >= h || my < 0 || my >= w ||
                        g[mx][my] == '#' || vis[mx][my] == tag)
                        continue;
                    vis[mx][my] = tag;
                    q.emplace(mx, my);
                }
            }
            stp--;
        }
    };
    int id = 0;
    for (int i = 0; i < n; i++) {
        int x, y, e;
        cin >> x >> y >> e;
        x--, y--;
        E[x][y] = e;
        // sp(x, y, e, ++id);
    }
    // cout << vis2 << endl;
    queue<pair<int, int>> q;
    q.emplace(sx, sy);
    vis[sx][sy] = 1;
    while (q.size()) {
        auto [x, y] = q.front();
        // cout << x << " " << y << endl;
        q.pop();
        if (g[x][y] == 'T') {
            cout << "Yes\n";
            return;
        }
        if (E[x][y])
            sp(x, y, E[x][y], ++id);
        for (int i = 0; i < 4; i++) {
            int mx = x + (i - 1) % 2;
            int my = y + (i - 2) % 2;
            if (mx < 0 || mx >= h || my < 0 || my >= w || vis[mx][my] == 0 ||
                vis2[mx][my] == 1)
                continue;
            vis2[mx][my] = 1;
            q.emplace(mx, my);
        }
    }
    cout << "No\n";
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