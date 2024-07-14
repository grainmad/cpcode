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
    int n;
    cin >> n;
    vector g(3, vector<int>(n));
    for (int j=0; j<3; j++)
        for (auto& i:g[j]) cin >> i;
    ll tot = accumulate(g[0].begin(), g[0].end(), 0LL);
    
    vector<pair<int,int>> ans(3);
    vector<int> vis(3);
    function<bool(int, int, ll)> dfs = [&](int who, int p, ll s) {
        // cout << who << " " << p << " " << s << endl;
        if (s >= (tot+2)/3) {
            if (who>=0) ans[who].second = p-1;
            if (vis[0] && vis[1] && vis[2]) {
                ans[who].second = n-1;
                return true;
            }
            if (p == n) return false;
            for (int i=0; i<3; i++) {
                if (vis[i]) continue;
                vis[i] = 1;
                ans[i].first = p;
                if (dfs(i, p+1, g[i][p])) return true;
                vis[i] = 0;
            }
        } else if (p == n) {
            return false;
        } else {
            if (dfs(who, p+1, s+g[who][p])) return true;
        }
        return false;
    };
    if (dfs(-1, 0, tot)) {
        // cout << ans << endl;
        for (auto [x,y]:ans) {
            cout << x+1 << " " << y+1 << " ";
        }
        cout << "\n";
    } else {
        cout << "-1\n";
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