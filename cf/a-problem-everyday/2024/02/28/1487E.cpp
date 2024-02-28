
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
template<class t> ostream& operator<<(ostream& os,const multiset<t>& v) {
    os<<'['; int s = 1;
    for(auto e:v) { if (s) s = 0; else os << ", "; os << e; }
    return os<<']';
}


void sol() {
    int n[4];
    for (int i=0; i<4; i++) cin >> n[i];
    vector<vector<ll>> a(4), dp(4);
    for (int i=0; i<4; i++) {
        dp[i].resize(n[i], -1);
        for (int j=0; j<n[i]; j++) {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    vector<vector<vector<int>>> g(3);
    for (int i=0; i<3; i++) {
        int t;
        cin >> t;
        g[i].resize(n[i+1]);
        while (t--) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            g[i][y].push_back(x);
        }
    }
    dp[0] = a[0];
    for (int i=1; i<=3; i++) {
        multiset<ll> st(dp[i-1].begin(), dp[i-1].end());
        for (int j=0; j<n[i]; j++) {
            for (int k:g[i-1][j]) {
                st.erase(st.find(dp[i-1][k]));
            }
            if (st.size())
                dp[i][j] = *st.begin()+a[i][j];
            else 
                dp[i][j] = MOD;
            for (int k:g[i-1][j]) {
                st.insert(dp[i-1][k]);
            }
        }
        // cout << dp[i] << endl;
    }
    // cout << dp << endl;
    int ans = *min_element(dp[3].begin(), dp[3].end());
    cout << (ans>=MOD?-1:ans) << "\n";
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
