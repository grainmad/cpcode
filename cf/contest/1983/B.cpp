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
    int n, m;
    cin >> n >> m;
    vector<string> g(n), h(n);
    for (auto& i:g) {
        cin >> i;
    }
    for (auto& i:h) {
        cin >> i;
    }
    vector<vector<int>> gi(n, vector<int>(m)), hi(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            gi[i][j] = g[i][j]-'0';
            hi[i][j] = h[i][j]-'0';
        }
    }
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<m-1; j++) {
            while(gi[i][j] != hi[i][j]) {
                gi[i][j] = (gi[i][j]+1)%3;
                gi[i+1][j+1] = (gi[i+1][j+1]+1)%3;
                gi[i][j+1] = (gi[i][j+1]+2)%3;
                gi[i+1][j] = (gi[i+1][j]+2)%3;
            }
        }
    }
    // cout << gi << " " << hi << endl;
    int ok = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (gi[i][j] != hi[i][j]) ok = 0;
        }
    }
    cout << (ok?"YES":"NO") << "\n";
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