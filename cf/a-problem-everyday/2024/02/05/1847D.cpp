
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

struct Seg{
	int l, r;
	ll val, tag;
} seg[N<<2];


// 将当前区间的懒标记，作用到左右区间（改变区间值），并将标记传递给子区间（累加，子区间可能存在未传递的懒标记），删除当前区间的懒标记。
void push_down(Seg& u, Seg& l, Seg& r) {
    if (u.tag == 0) return ;
	l.val = u.tag;
	l.tag = u.tag;
	r.val = u.tag;
	r.tag = u.tag;
	u.tag = 0;
}

void seg_build(int id, int l, int r, int val) {
	seg[id].l = l; seg[id].r = r;
	if (l == r) {
        seg[id].val = val;
		return ;
	}
	int m = l+r>>1;
	seg_build(id<<1, l, m, val);
	seg_build(id<<1|1, m+1, r, val);
}

void seg_update(int id, int l, int r, ll val) {
	if (l <= seg[id].l && seg[id].r <= r) {
		seg[id].val = val;
		seg[id].tag = val;
		return ;
	}
	push_down(seg[id], seg[id<<1], seg[id<<1|1]);
	int m = seg[id].l + seg[id].r >> 1;
	if (l <= m) seg_update(id<<1, l, r, val);
	if (m < r) seg_update(id<<1|1, l, r, val);
}

ll seg_query(int id, int p) {
	if (seg[id].l == seg[id].r) {
		return seg[id].val;
	}
	push_down(seg[id], seg[id<<1], seg[id<<1|1]);
	int m = seg[id].l + seg[id].r >> 1;
	if (p <= m) return seg_query(id<<1, p);
	else return seg_query(id<<1|1, p);
}

ll BIT[N];
// ll xBIT[N];

void bit_add(int x, ll val) {
    for (int i=x; i<N; i+=i&-i) {
        BIT[i] += val;       
        // xBIT[i] += x*val;
        // 区间查询时 BIT[i] += val; xBIT[i] += x*val;
    }
}

ll bit_ps(int x) {
    ll rt = 0;
    for (int i=x; i>0; i-=i&-i) {
        rt += BIT[i];
        // rt += x*BIT[i]-xBIT[i];
        // 区间查询时 rt += (x+1)*BIT[i]-xBIT[i];
    }
    return rt;
}

void sol() {
    int n, m, q;
    cin >> n >> m >> q;
    string s;
    cin >> s;
    s = "#" + s;
    vector<pair<int,int>> sg(m);
    for (auto& [i,j]:sg) cin >> i >> j;
    reverse(sg.begin(), sg.end());
    seg_build(1, 1, n, m+1);
    for (int i=0; i<m; i++) {
        auto [l, r] = sg[i];
        seg_update(1, l, r, m-i);
    }
    vector<int> v(n+1);
    for (int i=1; i<=n; i++) {
        v[i] = seg_query(1, i);
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 1);
    sort(idx.begin(), idx.end(), [&](int x, int y) {
        int vx = v[x], vy = v[y];
        if (vx == vy) return x < y;
        return vx < vy;
    });
    int cov = 0;
    for (int i=1; i<=n; i++) {
        if (v[i] != m+1) cov++;
    }
    string rs = "@";
    vector<int> rid(n+1);
    for (int i=0; i<n; i++) {
        rid[idx[i]] = i+1;
        rs.push_back(s[idx[i]]);
        if (s[idx[i]] == '1') bit_add(i+1, 1);
    }
    int c1 = count(s.begin(), s.end(), '1');
    while (q--) {
        int x;
        cin >> x;
        x = rid[x];
        int v;
        if (rs[x] == '1') rs[x] = '0', v = -1;
        else rs[x] = '1', v = 1;
        bit_add(x, v);
        c1 += v;
        int cnt = min(c1, cov);
        cout << cnt-bit_ps(cnt) << "\n";
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
