
#include <bits/stdc++.h>
// #define SINGLE_INPUT
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
    string s(m, '1');
    vector<int> fa(n+1, -1);
    function<int(int)> ufind = [&](int x) {
        return fa[x] < 0 ? x: fa[x] = ufind(fa[x]);
    };
    vector<vector<pair<int,int>>> g(n+1);
    vector<pair<int,int>> e;
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        e.emplace_back(x, y);
        g[x].emplace_back(y, i);
        g[y].emplace_back(x, i);
        int fx = ufind(x), fy = ufind(y);
        if (fx != fy) {
            fa[fx] = fy;
        } else {
            s[i] = '0';
        }
    }
    if (m-n+1 < 3){
        cout << s << "\n";
        return ;
    }
    // cout << s << endl;
    map<int,int> mp;
    for (int i=0; i<m; i++) {
        if (s[i] == '0') {
            auto [x, y] = e[i];
            // cout << i << " " << x << " " << y << endl;
            mp[x]++;
            mp[y]++;
        }
    }
    // cout << mp << endl;
    int ok = 0;
    for (auto [x,y]:mp) {
        if (y != 2) ok = 1;
    }
    if (!ok) {
        int p = 0;
        while (s[p] == '1') p++;
        // cout << p << endl;
        s[p] = '1';
        for (int& i:fa) i = -1;
        auto [x,y] = e[p];
        fa[x] = y;
        for (int i=0; i<m; i++) {
            if (i == p) continue;
            auto [x, y] = e[i];
            int fx = ufind(x), fy = ufind(y);
            if (fx != fy && s[i] != '0') {
                fa[fx] = fy;
            } else {
                s[i] = '0';
            }
        }
    }
    cout << s << "\n";
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
