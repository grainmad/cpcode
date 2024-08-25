#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
#define INF 0x3f3f3f3f
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

int ch[256];

void sol() {
    int n, q;
    cin >> n >> q;
    string s;
    vector<int> c(n);
    vector g(1<<4, vector<int>());
    for (int i=0; i<n; i++) {
        cin >> s;
        c[i] = 1<<ch[s[0]] | 1<<ch[s[1]];
        g[c[i]].push_back(i);
    }
    for (int i=0; i<q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (c[x]&c[y]) {
            cout << abs(x-y) << "\n";
        } else {
            int ans = INF;
            for (int i=0; i<4; i++) if (c[x]>>i&1) {
                for (int j=0; j<4; j++) if (c[y]>>j&1) {
                    int m = 1<<i | 1<<j;
                    auto& v = g[m];
                    if (v.empty()) continue;
                    auto it1 = lower_bound(v.begin(), v.end(), x);
                    if (it1 != v.end()) {
                        ans = min(ans, abs(*it1-x)+abs(*it1-y));
                    }
                    if (it1 != v.begin()) {
                        --it1;
                        ans = min(ans, abs(*it1-x)+abs(*it1-y));
                    }
                    auto it2 = lower_bound(v.begin(), v.end(), y);
                    if (it2 != v.end()) {
                        ans = min(ans, abs(*it2-x)+abs(*it2-y));
                    }
                    if (it2 != v.begin()) {
                        --it2;
                        ans = min(ans, abs(*it2-x)+abs(*it2-y));
                    }
                }
            }
            cout << (ans == INF ? -1 : ans) << "\n";
        }
    }
}

int main() {
    ch['R'] = 0;
    ch['G'] = 1;
    ch['B'] = 2;
    ch['Y'] = 3;
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