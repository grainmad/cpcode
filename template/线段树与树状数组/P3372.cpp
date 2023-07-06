#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
using namespace std;


// ll a[N];

// struct Seg{
// 	int l, r;
// 	ll val, tag;
// } sg[N<<2];

// void push_up(Seg& u, const Seg& l, const Seg& r) {
// 	u.val = l.val + r.val;
// }

// void push_down(Seg& u, Seg& l, Seg& r) {
// 	l.val += u.tag*(l.r-l.l+1);
// 	l.tag += u.tag;
// 	r.val += u.tag*(r.r-r.l+1);
// 	r.tag += u.tag;
// 	u.tag = 0;
// }

// void sg_build(int id, int l, int r) {
// 	sg[id].l = l; sg[id].r = r;
// 	if (l == r) {
// 		sg[id].val = a[l];
// 		// cin >> sg[id].val;
// 		return ;
// 	}
// 	int m = l+r>>1;
// 	sg_build(id<<1, l, m);
// 	sg_build(id<<1|1, m+1, r);
// 	push_up(sg[id], sg[id<<1], sg[id<<1|1]);
// }

// void sg_update(int id, int l, int r, ll val) {
// 	if (l <= sg[id].l && sg[id].r <= r) {
// 		sg[id].val += val*(sg[id].r-sg[id].l+1);
// 		sg[id].tag += val;
// 		return ;
// 	}
// 	push_down(sg[id], sg[id<<1], sg[id<<1|1]);
// 	int m = sg[id].l+sg[id].r>>1;
// 	if (l <= m) sg_update(id<<1, l, r, val);
// 	if (m < r) sg_update(id<<1|1, l, r, val);
// 	push_up(sg[id], sg[id<<1], sg[id<<1|1]);
// }

// ll sg_query(int id, int l, int r) {
// 	if (l <= sg[id].l && sg[id].r <= r) {
// 		return sg[id].val;
// 	}
// 	push_down(sg[id], sg[id<<1], sg[id<<1|1]);
// 	ll rt = 0;
// 	int m = sg[id].l + sg[id]. r >> 1;
// 	if (l <= m) rt += sg_query(id<<1, l, r);
// 	if (m < r) rt += sg_query(id<<1|1, l, r);
// 	return rt;
// }


// void sg_print() {
// 	for (int i=1; i<(N<<2); i++) {
// 		if (sg[i].l != 0)
// 		cout << "id:" << i << " [" << sg[i].l << "," << sg[i].r << "] val:" << sg[i].val << " tag:" << sg[i].tag << endl;
// 	}
// }


// void sol() {
// 	int n, m;
// 	cin >> n >> m;
// 	// for (int i=1; i<=n; i++) cin >> a[i];
// 	sg_build(1, 1, n);	
// 	// sg_print();
// 	for (int i=0; i<m; i++) {
// 		int o, x, y;
// 		ll k;
// 		cin >> o;
// 		if (o == 1) {
// 			cin >> x >> y >> k;
// 			sg_update(1, x, y, k);
// 		} else {
// 			cin >> x >> y;
// 			cout << sg_query(1, x, y) << endl;
// 		}
// 	}

// }
#define ll long long
#define N 100005
struct Seg {
    ll l, r, val, tag, ls, rs;
} seg[N<<2];
int sz = 0;
// seg[1].l = 0, seg[1].r = 1e9;
int newSeg(ll l, ll r) {
	seg[sz].l = l, seg[sz].r = r;
	return sz++;
}

void push_up(int u) {
  seg[u].val = seg[seg[u].ls].val + seg[seg[u].rs].val;
}
void push_down(int u) {
	auto& cur = seg[u];
    ll l = cur.l, r = cur.r, m = (r-l)/2+l;
    if (cur.ls == 0) {
        cur.ls = newSeg(l, m);
    }
    if (cur.rs == 0) {
    	cur.rs = newSeg(m+1, r);
    }
    if (cur.tag) {
        seg[cur.ls].val += cur.tag*(seg[cur.ls].r - seg[cur.ls].l + 1);
        seg[cur.ls].tag += cur.tag;
        seg[cur.rs].val += cur.tag*(seg[cur.rs].r - seg[cur.rs].l + 1);
        seg[cur.rs].tag += cur.tag;
        cur.tag = 0;
    }
}

void seg_update(int u, ll l, ll r, ll val) {
    if (l <= seg[u].l && seg[u].r <= r) {
        seg[u].val+=val*(seg[u].r - seg[u].l + 1);
        seg[u].tag+=val;
        return ;
    }
    push_down(u);
    ll m = (seg[u].r-seg[u].l)/2+seg[u].l;
    if (l<=m) seg_update(seg[u].ls, l, r, val);
    if (m<r) seg_update(seg[u].rs, l, r, val);
    push_up(u);
}
ll seg_query(int u, ll l, ll r) {
    if (l <= seg[u].l && seg[u].r <= r) {
        return seg[u].val;
    }
    push_down(u);
    ll rt = 0;
    ll m = (seg[u].r-seg[u].l)/2+seg[u].l;
    if (l<=m) rt += seg_query(seg[u].ls, l, r);
    if (m<r) rt += seg_query(seg[u].rs, l, r);
    return rt;
}
void sol() {
	newSeg(0, 1e9);
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		ll x; cin >> x;
		seg_update(0, i, i, x);
	}
	// sg_print();
	for (int i=0; i<m; i++) {
		int o, x, y;
		ll k;
		cin >> o;
		if (o == 1) {
			cin >> x >> y >> k;
			seg_update(0, x, y, k);
		} else {
			cin >> x >> y;
			cout << seg_query(0, x, y) << endl;
		}
	}

}
int main() {
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