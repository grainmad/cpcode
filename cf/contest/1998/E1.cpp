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

template<class T, class Compare=std::less<T>>
struct ST {
    Compare cmp;
    vector<vector<T>> st;  // st[i][j] 代表区间[i, i+2^j)最小值
    ST(const vector<T>& a, Compare cmp = Compare()) : st(a.size(), vector<T>(30)), cmp(cmp) {
        int sz = a.size();
        for (int i = 0; i < sz; i++)
            st[i][0] = a[i];
        for (int j = 1; (1 << j) <= sz; j++) {             // 区间大小
            for (int i = 0; i + (1 << j) - 1 < sz; i++) {  // 区间下限
                T x = st[i][j - 1], y = st[i + (1 << (j - 1))][j - 1];
                st[i][j] = min(x, y, cmp);
            }
        }
    }
    T ask(int l, int r) {
        int k = 0;
        while ((1 << (k + 1)) <= r - l + 1)
            k++;
        T x = st[l][k], y = st[r - (1 << k) + 1][k];
        return min(x, y, cmp);
    }
};

void sol() {
    int n, x;
    cin >> n >> x;
    vector<int> bad(n+1);
    vector<pair<int,int>> a;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        a.emplace_back(x, i);
    }
    ST<pair<int,int>, greater<>> st(a);
    auto dfs = [&](auto& self, int l, int r)->ll {
        if (l>r) return 0;
        auto [v, m] = st.ask(l, r);
        ll ls = self(self, l, m-1), rs = self(self, m+1, r);
        if (ls<v) {
            bad[l]++;
            bad[m]--;
        }
        if (rs<v) {
            bad[m+1]++;
            bad[r+1]--;
        }
        return ls+rs+v;
    };
    dfs(dfs, 0, n-1);
    ll ps = 0, ans = 0;
    for (int i=0; i<n; i++) {
        ps += bad[i];
        ans += (ps==0);
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