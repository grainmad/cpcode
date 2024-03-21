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
    int n;
    cin >> n;
    vector<vector<int>> v(2, vector<int>(n));
    vector<string> g(2);
    for (auto& i : g)
        cin >> i;
    // cout << g << endl;
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    v[0][0] = 1;
    int ok = 0;
    while (q.size()) {
        auto [x, y] = q.front();
        if (x == 1 && y == n - 1)
            ok = 1;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int mx = x + (i - 1) % 2;
            int my = y + (i - 2) % 2;
            if (mx < 0 || mx >= 2 || my < 0 || my >= n ||
                v[mx][my + (g[mx][my] == '<' ? -1 : 1)])
                continue;
            v[mx][my + (g[mx][my] == '<' ? -1 : 1)] = 1;
            q.emplace(mx, my + (g[mx][my] == '<' ? -1 : 1));
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
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
