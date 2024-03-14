#include <bits/stdc++.h>
// #define SINGLE_INPUT
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


void sol() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> f(m + 1, vector<int>(n));  // f[i][j] 第i轮j是否占领
    f[0][x - 1] = 1;
    for (int i = 1; i <= m; i++) {
        int r;
        cin >> r;
        string c;
        cin >> c;
        if (c == "0") {
            for (int j = 0; j < n; j++) {
                if (f[i - 1][j])
                    f[i][(j + r) % n] = 1;
            }
        } else if (c == "1") {
            for (int j = 0; j < n; j++) {
                if (f[i - 1][j])
                    f[i][(j - r + n) % n] = 1;
            }
        } else {
            for (int j = 0; j < n; j++) {
                if (f[i - 1][j]) {
                    f[i][(j + r) % n] = 1;
                    f[i][(j - r + n) % n] = 1;
                }
            }
        }
    }
    vector<int> t;
    for (int i = 0; i < n; i++) {
        if (f[m][i]) {
            t.push_back(i + 1);
        }
    }
    cout << t.size() << "\n";
    for (auto i : t) {
        cout << i << " ";
    }
    cout << "\n";
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