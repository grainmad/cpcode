
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 200005
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

#define LS (id << 1)
#define RS (id << 1 | 1)
ll sum[4 * N];

void push_up(int id) {
    sum[id] = sum[LS] + sum[RS];
}

void build(int id, int l, int r) {
    sum[id] = 0;
    if (l == r) {
        return;
    }
    int m = l + r >> 1;
    build(LS, l, m);
    build(RS, m + 1, r);
}
// 单点增加v
void add(int id, int l, int r, int q, ll v) {
    if (l == r && l == q) {
        sum[id] += v;
        return;
    }
    int m = l + r >> 1;
    if (q <= m)
        add(LS, l, m, q, v);
    if (m < q)
        add(RS, m + 1, r, q, v);
    push_up(id);
}


// 二分找第th个非0值的下标
int bs(int id, int l, int r, int th) {
    if (l == r) return l;
    int m = l+r>>1;
    if (sum[LS]>=th) return bs(LS, l, m, th);
    else return bs(RS, m+1, r, th-sum[LS]);
}

// 区间查询和
// ll ask(int id, int l, int r, int ql, int qr) {
//     if (ql <= l && r <= qr) {
//         return sum[id];
//     }
//     int m = l + r >> 1;
//     ll rt = 0;
//     if (ql <= m)
//         rt += ask(LS, l, m, ql, qr);
//     if (m < qr)
//         rt += ask(RS, m + 1, r, ql, qr);
//     return rt;
// }

void sol() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    map<int,vector<int>, greater<int>> mp;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    build(1, 1, n);
    int m;
    cin >> m;
    vector<pair<int,int>> q(m);
    for (auto& [i,j]:q) cin >> i >> j;
    vector<int> idx(m);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) {
        return q[x] < q[y];
    });
    vector<int> ans(m);
    int p = 0, sz = 0;
    for (auto& [i,j]:mp) {
        // cout << i << " " << j << endl;
        for (int c:j) {
            add(1, 1, n, c, 1);
            sz++;
            while (p<m && q[idx[p]].first==sz) {
                ans[idx[p]] = a[bs(1, 1, n, q[idx[p]].second)];
                p++;
            }
        }
    }
    // cout << ans << endl;
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
