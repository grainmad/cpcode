
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& i:a) cin >> i, i--;
    for (auto& i:b) cin >> i, i--;
    vector<int> fa(n, -1), ce(n, 0), cv(n, 1), cy(n, 0);
    auto merge = [&](int x, int y) {
        ce[x] += ce[y];
        cv[x] += cv[y];
        cy[x] |= cy[y];
        fa[y] = x;
    };
    function<int(int)> ufind = [&](int x) {
        return fa[x] == -1 ? x : fa[x] = ufind(fa[x]);
    };
    for (int i=0; i<n; i++) {
        int fx = ufind(a[i]), fy = ufind(b[i]);
        if (fx != fy) merge(fx, fy);
        ce[fx]++;
        if (a[i] == b[i]) cy[ufind(a[i])] = 1;
    }
    ll ans = 1;
    for (int i=0; i<n; i++) {
        if (fa[i] != -1) continue;
        if (ce[i] != cv[i]) ans = 0;
        ans = ans*(cy[i] ? n : 2)%MOD;
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
