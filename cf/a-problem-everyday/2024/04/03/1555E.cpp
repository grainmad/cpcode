
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 1000005
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

// 可区间增加，求维护区间最小值
// 可查询区间是否覆盖
#define LS (id << 1)
#define RS (id << 1 | 1)
ll tag[4 * N], mn[4 * N];

void push_up(int id) {
    mn[id] = min(mn[LS], mn[RS]);
}

void push_down(int id) {
    if (tag[id]) {
        mn[LS] += tag[id];
        mn[RS] += tag[id];
        tag[LS] += tag[id];
        tag[RS] += tag[id];
        tag[id] = 0;
    }
}

void build(int id, int l, int r) {
    tag[id] = mn[id] = 0;
    if (l == r) {
        return;
    }
    int m = l + r >> 1;
    build(LS, l, m);
    build(RS, m + 1, r);
    push_up(id);
}

// 区间增加v
void add(int id, int l, int r, int ql, int qr, ll v) {
    if (ql <= l && r <= qr) {
        mn[id] += v;
        tag[id] += v;
        return;
    }
    push_down(id);
    int m = l + r >> 1;
    if (ql <= m)
        add(LS, l, m, ql, qr, v);
    if (m < qr)
        add(RS, m + 1, r, ql, qr, v);
    push_up(id);
}

struct Node {
    int l, r, w;
    Node(int l=0, int r=0, int w=0):l(l),r(r),w(w) {}
    bool operator<(const Node& o) const {
        return w < o.w;
    }
};
ostream& operator<<(ostream& os, const Node& v) {
    os<<'['; 
    auto [l, r, w] = v;
    os << l << ", " << r << ", " << w;
    return os<<']';
}

void sol() {
    int n, m;
    cin >> n >> m;
    vector<Node> a(n);
    for (auto& [l,r,w]:a) cin >> l >> r >> w, r--;
    sort(a.begin(), a.end());
    // cout << a << endl;
    build(1, 1, m-1);
    ll ans = 1e9;
    for (int l=0, r=0; l<n; l++) {
        while (r<n && mn[1] == 0) {
            add(1, 1, m-1, a[r].l, a[r].r, 1);
            r++;
        }
        // cout << l << " " << r << endl;
        // cout << mn[1] << "\n";
        if (mn[1] != 0)
            ans = min(ans, (a[r-1].w - a[l].w)*1LL);
        add(1, 1, m-1, a[l].l, a[l].r, -1);
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
