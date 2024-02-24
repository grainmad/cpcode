
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
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto& i:g) cin >> i;
    int sz = max(n, m);
    int mn = min(n, m);
    if (mn >= 4) {
        cout << "-1\n";
        return ;
    }
    
    vector<int> v(sz);
    if (n>m) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                v[i] = v[i]*2+g[i][j]-'0';
            }
        }
    } else {
        for (int j=0; j<m; j++) {
            for (int i=0; i<n; i++) {
                v[j] = v[j]*2+g[i][j]-'0';
            }
        }
    }
    // cout << v << endl;
    auto bct = [](int x) {
        int rt = 0;
        for (int i=x; i; i=i&(i-1)) rt++;
        return rt;
    };
    if (mn == 1) {
        cout << "0\n";
    } else if (mn == 2) {
        vector<vector<int>> tr = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
        vector<vector<int>> dp(sz, vector<int>(4, n*m));
        for (int i=0; i<4; i++) {
            dp[0][i] = bct(i^v[0]);
        }
        for (int i=1; i<sz; i++) {
            for (int j=0; j<4; j++) {
                dp[i][j] = min(dp[i-1][tr[j][0]], dp[i-1][tr[j][1]])+bct(j^v[i]);
            }
        }
        // cout << dp << endl;
        cout << *min_element(dp[sz-1].begin(), dp[sz-1].end()) << "\n";

    } else {
        // 000
        // 001
        // 010
        // 011
        // 100
        // 101
        // 110
        // 111
        vector<vector<int>> tr = {{2, 5}, {3, 4}, {0, 7}, {1, 6}, {1, 6}, {0, 7}, {3, 4}, {2, 5}};
        vector<vector<int>> dp(sz, vector<int>(8, n*m));
        for (int i=0; i<8; i++) {
            dp[0][i] = bct(i^v[0]);
        }
        for (int i=1; i<sz; i++) {
            for (int j=0; j<8; j++) {
                dp[i][j] = min(dp[i-1][tr[j][0]], dp[i-1][tr[j][1]])+bct(j^v[i]);
            }
        }
        // cout << dp << endl;
        cout << *min_element(dp[sz-1].begin(), dp[sz-1].end()) << "\n";
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
