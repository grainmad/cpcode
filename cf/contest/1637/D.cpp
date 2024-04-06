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
    vector<int> a(n+1), b(n+1);
    ll s = 0, mn = 0, mx = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
    }
    for (int i=1; i<=n; i++) {
        if (a[i] > b[i]) swap(a[i], b[i]);
        s += a[i]*a[i] + b[i]*b[i];
        mn += a[i];
        mx += b[i];
    }
    s *= n-2;
    // f[i][j] 前i个数能否凑出j [0, mx-mn]
    bitset<10005> f(1);
    for (int i=1; i<=n; i++) {
        f |= f<<(b[i] - a[i]);
    }
    ll ans = 1e15;
    for (int i=0; i<=mx-mn; i++) {
        if (f[i]) {
            // a = mn+i b = mn+mx-a = mx-i;
            ans = min(ans, s+(mn+i)*(mn+i)+(mx-i)*(mx-i));
        }
    }
    cout << ans << "\n";
}

void sol2() {
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    ll s = 0, c = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        s += a[i]*a[i];
        c += a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
        s += b[i]*b[i];
        c += b[i];
    }
    s *= n-2;
    set<pair<int,int>> st;
    ll ans = 1e15;
    function<void(int,int)> dfs = [&](int x, int y) {
        if (st.count({x, y})) return ;
        if (x == n) {
            ans = min(ans, s + y*y + (c-y)*(c-y));
            return ;
        }
        st.insert({x,y});
        dfs(x+1, y+a[x+1]);
        dfs(x+1, y+b[x+1]);
    };
    dfs(0, 0);
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