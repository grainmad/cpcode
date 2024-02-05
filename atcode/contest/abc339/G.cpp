#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
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


#define N 200005
#define lc(x) tr[x].l
#define rc(x) tr[x].r
struct node {
    int l, r;
    ll s;
} tr[N * 25];
// n(logn+3)?

int root[N], idx;

// 初始版本构建build(root[0], l, r)
void build(int& x, int l, int r) {
    x = ++idx;
    if (l == r)
        return;
    int m = l + r >> 1;
    build(lc(x), l, m);
    build(rc(x), m + 1, r);
}

// 单点插入，拷贝前一版本的一条路径
void insert(int x, int& y, int l, int r, int pos, ll val) {
    y = ++idx;
    tr[y] = tr[x];
    if (l == r) {
        tr[y].s += val;
        return;
    }
    int m = l + r >> 1;
    if (pos <= m)
        insert(lc(x), lc(y), l, m, pos, val);
    else
        insert(rc(x), rc(y), m + 1, r, pos, val);
    tr[y].s = tr[lc(y)].s + tr[rc(y)].s;
}

// 查询前缀区间[... pos]的和
ll presum(int x, int l, int r, int pos) {
    if (l == r)
        return tr[x].s;
    int m = l + r >> 1;
    if (m < pos) {
        return tr[lc(x)].s + presum(rc(x), m+1, r, pos);
    } else {
        return presum(lc(x), l, m, pos);
    }
}

// 查询区间和
ll query(int x, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return tr[x].s;
    int m = l + r >> 1;
    // 判断查询区间[ql, qr] 覆盖[l,m], [m+1,r]的情况。
    ll rt = 0;
    if (ql<=m) {
        rt += query(lc(x), l, m, ql, qr);
    } 
    if (m<qr) {
        rt += query(rc(x), m+1, r, ql, qr);
    }
    return rt;
}

void sol() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& i:a) cin >> i;
    auto ua = a;
    sort(ua.begin(), ua.end());
    ua.erase(unique(ua.begin(), ua.end()), ua.end());
    auto id = [&](ll x) {
        int p = upper_bound(ua.begin(), ua.end(), x)-ua.begin();
        return p - 1;
    };
    
    int sz = ua.size();
    build(root[0], 0, sz-1);
    for (int i=1; i<=n; i++) {
        insert(root[i-1], root[i], 0, sz-1, id(a[i-1]), a[i-1]);
    }
    int q;
    cin >> q;
    ll pre = 0;
    while (q--) {
        ll x, y, z;
        cin >> x >> y >> z;
        ll l = x^pre;
        ll r = y^pre;
        ll u = z^pre;
        if (u < ua[0]) {
            pre = 0;
        } else {
            int p = id(u);
            pre = query(root[r], 0, sz-1, 0, p) - query(root[l-1], 0, sz-1, 0, p);
        }
        cout << pre << "\n";
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