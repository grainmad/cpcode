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
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    set<pair<int,int>> r, c;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        r.insert({x, y});
        c.insert({y, x});
    }
    int L = 0, U = 0, R = b+1, D = a+1;
    vector<int> ans(2);
    for (int i=0; i<m; i++) {
        string d;
        int k;
        cin >> d >> k;
        int cnt = 0;
        if (d == "U") {
            U += k;
            while (r.size() && r.begin()->first<=U) {
                auto [x, y] = *r.begin();
                if (c.count({y, x})) cnt++;
                r.erase(*r.begin());
            }
        }
        if (d == "D") {
            D -= k;
            while (r.size() && r.rbegin()->first>=D) {
                auto [x, y] = *r.rbegin();
                if (c.count({y, x})) cnt++;
                r.erase(*r.rbegin());
            }
        }
        if (d == "L") {
            L += k;
            while (c.size() && c.begin()->first<=L) {
                auto [x, y] = *c.begin();
                if (r.count({y, x})) cnt++;
                c.erase(*c.begin());
            }
        }
        if (d == "R") {
            R -= k;
            while (c.size() && c.rbegin()->first>=R) {
                auto [x, y] = *c.rbegin();
                if (r.count({y, x})) cnt++;
                c.erase(*c.rbegin());
            }
        }
        ans[i%2] += cnt;
        // cout << L << " " << R << " " << U << " " << D << "\n";
        // cout << cnt << "\n";
    }
    // cout << ans << "\n";
    cout << ans[0] << " " << ans[1] << "\n";
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