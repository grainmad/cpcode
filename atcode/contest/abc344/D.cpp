#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
#define INF 0x3f3f3f3f
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
    string s;
    cin >> s;
    int sz = s.size();
    s = "#"+s;
    int n;
    cin >> n;
    vector<vector<string>> g(n+1);
    for (int i=1; i<=n; i++) {
        int t;
        cin >> t;
        for (int j=0; j<t; j++) {
            string u;
            cin >> u;
            g[i].push_back(u);
        }
    }
    vector<vector<int>> f(n+1, vector<int>(sz+1, INF));
    for (int i=0; i<=n; i++) {
        f[i][0] = 0;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=sz; j++) { 
            f[i][j] = f[i-1][j];
            for (auto& u:g[i]) {
                int usz = u.size();
                if (j>=usz && u == s.substr(j-usz+1, usz)) f[i][j] = min(f[i][j], f[i-1][j-usz]+1);
            }
        }
    }
    // cout << f << endl;
    if (f[n][sz] == INF) cout << "-1\n";
    else cout << f[n][sz] << "\n";
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