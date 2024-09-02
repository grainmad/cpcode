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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector pre(n, vector<int>(26)), suf(n, vector<int>(26));
    vector<int> visp(n), viss(n);
    function<vector<int>(int)> get_pre = [&](int u) {
        if (u<0) return vector<int>(26);
        if (visp[u]) return pre[u];
        visp[u] = 1;
        auto v = get_pre(u-2);
        v[s[u]-'a']++;
        return pre[u] = v;
    };

    function<vector<int>(int)> get_suf = [&](int u) {
        if (u>=n) return vector<int>(26); 
        if (viss[u]) return suf[u];
        viss[u] = 1;
        auto v = get_suf(u+2);
        v[s[u]-'a']++;
        return suf[u] = v;
    };

    int ans = 0;
    if (n%2) {
        ans = n;
        for (int i=0; i<n; i++) {
            auto l1 = get_pre(i-2);
            auto r1 = get_suf(i+1);
            auto l2 = get_pre(i-1);
            auto r2 = get_suf(i+2);
            // cout << i << "-----------------------\n";
            int mx1 = 0, mx2 = 0;
            for (int j=0; j<26; j++) {
                mx1 = max(mx1, l1[j]+r1[j]);
                mx2 = max(mx2, l2[j]+r2[j]);
            }
            // cout<< mx1 << " " << mx2 << "\n";
            ans = min(ans, n/2-mx1+n/2-mx2);
        }
        ans++;
    } else {
        auto x = get_suf(0);
        auto y = get_suf(1);
        int mx1 = 0, mx2 = 0;
        for (int j=0; j<26; j++) {
            mx1 = max(mx1, x[j]);
            mx2 = max(mx2, y[j]);
        }
        ans = max(ans, n/2-mx1+n/2-mx2);
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