
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
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
#define LS (id << 1)
#define RS (id << 1 | 1)
ll sum[4 * N];

void push_up(int id) {
    sum[id] = sum[LS] + sum[RS];
}


void build(int id, int l, int r) {
    sum[id] = 0;
    if (l == r) {
        // sum[id] = a[l];
        return;
    }
    int m = l + r >> 1;
    build(LS, l, m);
    build(RS, m + 1, r);
    push_up(id);
}
// 单点增加v
void add(int id, int l, int r, int q, ll v) {
    if (l == r && l == q) {
        sum[id] = v;
        return;
    }
    int m = l + r >> 1;
    if (q <= m)
        add(LS, l, m, q, v);
    if (m < q)
        add(RS, m + 1, r, q, v);
    push_up(id);
}
// 区间查询和
ll ask(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return sum[id];
    }
    int m = l + r >> 1;
    ll rt = 0;
    if (ql <= m)
        rt += ask(LS, l, m, ql, qr);
    if (m < qr)
        rt += ask(RS, m + 1, r, ql, qr);
    return rt;
}

void sol() {
    int n;
    cin >> n;
    map<int,int> idx;
    map<int,vector<int>, greater<int>> Y;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        idx[x];
        Y[y].push_back(x);
    }
    int sz = 0;
    for (auto& [i,j]:idx) j=++sz;

    build(1, 1, sz);
    ll ans = 0;
    for (auto [i,j]:Y) {
        sort(j.begin(), j.end());
        // cout << i << " " << j << endl;
        for (auto k:j) {
            add(1, 1, sz, idx[k], 1);
        }    
        ll s = sum[1]*(sum[1]-1)/2 + sum[1];
        ll pre = 0;
        for (auto k:j) {
            add(1, 1, sz, idx[k], 0);
            ll cur = ask(1, 1, sz, 1, idx[k]);
            ll d = cur-pre;
            s -= d*(d-1)/2+d;
            pre = cur;
        }
        ll cur = ask(1, 1, sz, 1, sz);
        ll d = cur - pre;
        s -= d*(d-1)/2+d;
        for (auto k:j) {
            add(1, 1, sz, idx[k], 1);
        }
        // cout <<s << endl;
        ans += s;
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
