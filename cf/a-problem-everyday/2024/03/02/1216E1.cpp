
#include <bits/stdc++.h>
#define SINGLE_INPUT
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
    int n;
    cin >> n;
    vector<ll> a(n), idx(n);
    for (auto& i:a) cin >> i;
    int mx = *max_element(a.begin(), a.end());
    // int sz = (int) sqrt(mx+100);
    int sz = 1e5;
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) {
        return a[x] < a[y];
    });
    vector<char> ans(n);
    int u = 0;
    ll s = 0;
    vector<int> p(sz);
    vector<string> num(sz);
    num[0] = "0";
    for (int i=1; i<sz && u < n; i++) {
        num[i] = to_string(i);
        p[i] = p[i-1]+num[i].size();
        s += p[i];
        while (u<n && a[idx[u]] <= s) {
            ll add = s-p[i];
            int l = 1, r = i+1;
            while (l<r) {
                int m = l+r>>1;
                if (p[m]+add >= a[idx[u]]) {
                    r = m;
                } else {
                    l = m+1;
                }
            }
            // 最后一个小于的位置
            ll ps = a[idx[u]] - (p[r-1]+add);
            // cout << ps << endl;
            ans[idx[u]] = num[r][ps-1];
            u++;
        }
    }
    for (auto i:ans) {
        cout << i << "\n";
    }
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
