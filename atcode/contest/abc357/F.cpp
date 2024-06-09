#include <bits/stdc++.h>
#define SINGLE_INPUT
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

struct Seg{
	int l, r;
	ll len, val, sum1, sum2, tag1, tag2;
} seg[N<<2];

void push_up(Seg& u, const Seg& l, const Seg& r) {
	u.len = l.len + r.len;
    u.val = (l.val + r.val)%MOD;
    u.sum1 = (l.sum1 + r.sum1)%MOD;
    u.sum2 = (l.sum2 + r.sum2)%MOD;
}

// 将当前区间的懒标记，作用到左右区间（改变区间值），并将标记传递给子区间（累加，子区间可能存在未传递的懒标记），删除当前区间的懒标记。
void push_down(Seg& u, Seg& l, Seg& r) {
	if (u.tag1) {
        l.val = (l.val + u.tag1*l.sum2 % MOD) % MOD;
        l.sum1 = (l.sum1 + u.tag1*l.len % MOD) % MOD;
        l.tag1 = (l.tag1 + u.tag1)%MOD;

        r.val = (r.val + u.tag1*r.sum2 % MOD) % MOD;
        r.sum1 = (r.sum1 + u.tag1*r.len % MOD) % MOD;
        r.tag1 = (r.tag1 + u.tag1)%MOD;

        u.tag1 = 0;
    }
    if (u.tag2) {
        l.val = (l.val + u.tag2*l.sum1 % MOD) % MOD;
        l.sum2 = (l.sum2 + u.tag2*l.len % MOD) % MOD;
        l.tag2 = (l.tag2 + u.tag2)%MOD;

        r.val = (r.val + u.tag2*r.sum1 % MOD) % MOD;
        r.sum2 = (r.sum2 + u.tag2*r.len % MOD) % MOD;
        r.tag2 = (r.tag2 + u.tag2)%MOD;

        u.tag2 = 0;
    }
}

void seg_build(int id, int l, int r, vector<ll>& a, vector<ll>& b) {
	seg[id].l = l; seg[id].r = r;
    seg[id].len = r-l+1;
	if (l == r) {
        seg[id].sum1 = a[l-1]%MOD;
        seg[id].sum2 = b[l-1]%MOD;
		seg[id].val = a[l-1]*b[l-1]%MOD;
        seg[id].tag1 = seg[id].tag2 = 0;
		// cin >> seg[id].val;
		return ;
	}
	int m = l+r>>1;
	seg_build(id<<1, l, m, a, b);
	seg_build(id<<1|1, m+1, r, a, b);
	push_up(seg[id], seg[id<<1], seg[id<<1|1]);
}

void seg_update1(int id, int l, int r, ll tag1) {
	if (l <= seg[id].l && seg[id].r <= r) {
		seg[id].val = (seg[id].val + tag1*seg[id].sum2 % MOD) % MOD;
        seg[id].sum1 = (seg[id].sum1 + tag1*seg[id].len % MOD) % MOD;
        seg[id].tag1 = (seg[id].tag1 + tag1)%MOD;
		return ;
	}
	push_down(seg[id], seg[id<<1], seg[id<<1|1]);
	int m = seg[id].l + seg[id].r >> 1;
	if (l <= m) seg_update1(id<<1, l, r, tag1);
	if (m < r) seg_update1(id<<1|1, l, r, tag1);
	push_up(seg[id], seg[id<<1], seg[id<<1|1]);
}

void seg_update2(int id, int l, int r, ll tag2) {
	if (l <= seg[id].l && seg[id].r <= r) {
		seg[id].val = (seg[id].val + tag2*seg[id].sum1 % MOD) % MOD;
        seg[id].sum2 = (seg[id].sum2 + tag2*seg[id].len % MOD) % MOD;
        seg[id].tag2 = (seg[id].tag2 + tag2)%MOD;
		return ;
	}
	push_down(seg[id], seg[id<<1], seg[id<<1|1]);
	int m = seg[id].l + seg[id].r >> 1;
	if (l <= m) seg_update2(id<<1, l, r, tag2);
	if (m < r) seg_update2(id<<1|1, l, r, tag2);
	push_up(seg[id], seg[id<<1], seg[id<<1|1]);
}

ll seg_query(int id, int l, int r) {
	if (l <= seg[id].l && seg[id].r <= r) {
		return seg[id].val;
	}
	push_down(seg[id], seg[id<<1], seg[id<<1|1]);
	ll rt = 0;
	int m = seg[id].l + seg[id].r >> 1;
	if (l <= m) rt = (rt + seg_query(id<<1, l, r))%MOD;
	if (m < r) rt = (rt + seg_query(id<<1|1, l, r))%MOD;
	return rt;
}

// void seg_print() {
// 	for (int i=1; i<(N<<2); i++) {
// 		if (seg[i].l != 0)
// 		cout << "id:" << i << " [" << seg[i].l << "," << seg[i].r << "] val:" << seg[i].val 
//         << " sum1:" << seg[i].sum1
//         << " sum2:" << seg[i].sum2
//         << " tag1:" << seg[i].tag1
//         << " tag2:" << seg[i].tag2 << endl;
// 	}
// }


void sol() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    for (auto& i:a) cin >> i;
    for (auto& i:b) cin >> i;
    seg_build(1, 1, n, a, b);
    // seg_print();
    for (int i=0; i<q; i++) {
        int o, l, r, x;
        cin >> o;
        if (o == 1) {
            cin >> l >> r >> x;
            seg_update1(1, l, r, x%MOD);
        }
        if (o == 2) {
            cin >> l >> r >> x;
            seg_update2(1, l, r, x%MOD);
        }
        if (o == 3) {
            cin >> l >> r;
            cout << seg_query(1, l, r) << endl;
        }
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