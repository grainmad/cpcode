
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
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
    vector g(n, vector<int>(m));
    for (auto& i:g) {
        for (auto& j:i) {
            cin >> j;
        }
    }
    auto pr = [&]() {
        for (auto& i:g) {
            for (auto& j:i) {
                cout << j << " ";
            }
            cout << "\n";
        }
        cout << endl;
    };
    auto check = [&](int x, int y) {
        if (x<0 || x+1>=n || y<0 || y+1>=m) return 0;
        int c = 0;
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                if (g[x+i][y+j] == 0) continue;
                if (c == 0) c = g[x+i][y+j];
                if (c != g[x+i][y+j]) return 0;
            }
        }
        return c;
    };
    auto set0 = [&](int x, int y) {
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                g[x+i][y+j] = 0;
            }
        }
    };
    vector<tuple<int,int,int>> ans;
    queue<pair<int,int>> q;
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<m-1; j++) {
            int rt = check(i,j);
            if (rt) {
                q.emplace(i,j);
                ans.emplace_back(i,j,rt);
                set0(i,j);
                // pr();
            }
        }
    }
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i=-1; i<2; i++) {
            for (int j=-1; j<2; j++) {
                int mx = x+i;
                int my = y+j;
                int rt = check(mx, my);
                if (rt) {
                    q.emplace(mx, my);
                    ans.emplace_back(mx, my, rt);
                    set0(mx, my);
                    // pr();
                }
            }
        }
    }
    for (auto& i:g) {
        for (auto& j:i) {
            if (j != 0) {
                cout << "-1\n";
                return ;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto [x, y, v]:ans) {
        cout << x+1 << " " << y+1 << " " << v << "\n";
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
