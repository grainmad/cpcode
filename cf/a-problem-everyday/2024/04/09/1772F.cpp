
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
    int n, m, k;
    cin >> n >> m >> k;
    vector g(k+1, vector<string>(n));
    for (auto& i:g) {
        for (auto& j:i) {
            cin >> j;
        }
    }
    // cout << g << "\n";
    auto dif = [&](int x, int y)->vector<pair<int,int>> {
        vector<pair<int,int>> rt;
        for (int i=1; i<n-1; i++) {
            for (int j=1; j<m-1; j++) {
                if (g[x][i][j] != g[y][i][j]) {
                    rt.emplace_back(i,j);
                }
            }
        }
        return rt;
    };
    auto getopt = [&](int x) {
        int c = 0;
        for (int i=1; i<n-1; i++) {
            for (int j=1; j<m-1; j++) {
                int ok = 1;
                for (int k=0; k<4; k++) {
                    if (g[x][i][j] == g[x][i+(k-1)%2][j+(k-2)%2])
                        ok = 0;
                }
                c += ok;
            }
        }
        return c;
    };
    vector<int> opt(k+1), idx(k+1);
    for (int i=0; i<=k; i++) opt[i] = getopt(i);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) {
        return opt[x] > opt[y];
    });
    vector<pair<int,int>> ans;
    for (int i=1; i<=k; i++) {
        if (opt[idx[i]] < opt[idx[i-1]]) {
            for (auto j:dif(idx[i-1], idx[i])) {
                ans.emplace_back(j);
            }
        }
        ans.emplace_back(-1, idx[i]);
    }
    cout << idx[0]+1 << "\n";
    cout << ans.size() << "\n";
    for (auto& [x, y]:ans) {
        if (x == -1) {
            cout << "2 " << y+1 << "\n";
        } else {
            cout <<  "1 " << x+1 << " " << y+1 << "\n";
        }
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
