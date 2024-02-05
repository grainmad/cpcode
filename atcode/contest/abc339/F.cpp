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

ll p[8] = {167772161,469762049,754974721,998244353,1045430273,1051721729,1053818881,1000000007};

void sol() {
    int n;
    cin >> n;
    vector<vector<ll>> g(n, vector<ll>(8));
    map<vector<ll>, int> mp;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (char j:s) {
            int u = j-'0';
            for (int k=0; k<8; k++) {
                g[i][k] = (g[i][k]*10+u)%p[k];
            }
        }
        mp[g[i]]++;
    }
    // cout << g << endl;
    
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            vector<ll> c(8);
            for (int k=0; k<8; k++) {
                c[k] = g[j][k]*g[i][k]%p[k];
            }
            if (mp.count(c)) ans+=mp[c];
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