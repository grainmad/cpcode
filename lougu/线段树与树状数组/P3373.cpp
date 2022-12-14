#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
using namespace std;

ll MOD = 571373;
ll a[N];
struct Seg {
	int l, r;
	ll val, tag1, tag2;
} sg[N<<2];

void push_up(int id) {
	sg[id].val = (sg[id<<1].val + sg[id<<1|1].val)%MOD;
}

void push_down(int id) {
	int l = id<<1, r = id<<1|1;
	ll tag1 = sg[id].tag1, tag2 = sg[id].tag2;
	sg[l].val = (sg[l].val*tag1%MOD+tag2*(sg[l].r-sg[l].l+1)%MOD)%MOD;
	sg[l].tag1 = (sg[l].tag1*tag1)%MOD;
	sg[l].tag2 = (sg[l].tag2*tag1%MOD+tag2)%MOD;
	sg[r].val = (sg[r].val*tag1%MOD+tag2*(sg[r].r-sg[r].l+1)%MOD)%MOD;
	sg[r].tag1 = (sg[r].tag1*tag1)%MOD;
	sg[r].tag2 = (sg[r].tag2*tag1%MOD+tag2)%MOD;
	sg[id].tag1 = 1;
	sg[id].tag2 = 0;
}

void sg_build(int id, int l, int r) {
	sg[id].l = l;
	sg[id].r = r;
	sg[id].tag1 = 1;
	if (l == r) {
		sg[id].val = a[l];
		return;
	}
	int m = l+r>>1;
	sg_build(id<<1, l, m);
	sg_build(id<<1|1, m+1, r);
	push_up(id);
	// sg[id].tag1 = 1;
}

void sg_update(int id, int l, int r, ll val, int opt) {
	if (l <= sg[id].l && sg[id].r <= r) {
		if (opt == 1) {
			sg[id].val = sg[id].val*val%MOD;//tag只作用给子节点
			sg[id].tag1 = sg[id].tag1*val%MOD;
			sg[id].tag2 = sg[id].tag2*val%MOD;
		} else {
			sg[id].val = (sg[id].val+val*(sg[id].r-sg[id].l+1)%MOD)%MOD;
			sg[id].tag2 = (sg[id].tag2 + val)%MOD;
		}
		return ;
	}
	push_down(id);
	int m = sg[id].l+sg[id].r>>1;
	if (l <= m) sg_update(id<<1, l, r, val, opt);
	if (m < r) sg_update(id<<1|1, l, r, val, opt);
	push_up(id);
}

ll sg_query(int id, int l, int r) {
	if (l <= sg[id].l && sg[id].r <= r) {
		return sg[id].val;
	}
	push_down(id);
	ll rt = 0;
	int m = sg[id].l+sg[id].r >> 1;
	if (l <= m) rt = (rt + sg_query(id<<1, l, r))%MOD;
	if (m < r) rt = (rt + sg_query(id<<1|1, l, r))%MOD;
	return rt;
}

void sol() {
	int n, m;
	cin >> n >> m >> MOD;
	for (int i=1; i<=n; i++) cin >> a[i];
	sg_build(1, 1, n);
	for (int i=0; i<m; i++) {
		ll o, x, y, k;
		cin >> o;
		if (o == 1) {
			cin >> x >> y >> k;
			sg_update(1, x, y, k, 1);
		} else if (o == 2) {
			cin >> x >> y >> k;
			sg_update(1, x, y, k, 2);
		} else {
			cin >> x >> y;
			cout << sg_query(1, x, y) << endl;
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