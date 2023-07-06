#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

ll a[N];

struct Seg{
	int l, r;
	ll pre, sfx, sum, max;
} sg[N<<2];

void push_up(Seg& u, const Seg& l, const Seg& r) {
	u.sum = l.sum + r.sum;
	u.pre = max(l.pre, l.sum+r.pre);
	u.sfx = max(r.sfx, r.sum+l.sfx);
	u.max = max({l.sfx+r.pre, l.max, r.max});
}

void sg_build(int id, int l, int r) {
	sg[id].l = l; sg[id].r = r;
	if (l == r) {
		sg[id].sum = sg[id].pre = sg[id].sfx = sg[id].max = a[l];
		return ;
	}
	int m = l+r>>1;
	sg_build(id<<1, l, m);
	sg_build(id<<1|1, m+1, r);
	push_up(sg[id], sg[id<<1], sg[id<<1|1]);
}

void sg_update(int id, int p, ll val) {
	if (p == sg[id].l && sg[id].r == p) {
		sg[id].sum = sg[id].pre = sg[id].sfx = sg[id].max = val;
		return ;
	}
	int m = sg[id].l+sg[id].r>>1;
	if (p <= m) sg_update(id<<1, p, val);
	if (m < p) sg_update(id<<1|1, p, val);
	push_up(sg[id], sg[id<<1], sg[id<<1|1]);
}

Seg sg_query(int id, int l, int r) {
	if (l <= sg[id].l && sg[id].r <= r) {
		return sg[id];
	}

	ll rt = -N;
	int m = sg[id].l + sg[id].r >> 1;
	if (l <= m && m < r) {
		Seg rt;
		push_up(rt, sg_query(id<<1, l, r), sg_query(id<<1|1, l, r));
		return rt;
	} else if (l <= m) {
		return sg_query(id<<1, l, r);
	} else return sg_query(id<<1|1, l, r);
}


void sg_print() {
	// for (int i=1; i<(N<<2); i++) {
	// 	if (sg[i].l != 0)
	// 	cout << "id:" << i << " [" << sg[i].l << "," << sg[i].r << "] val:" << sg[i].val << " tag:" << sg[i].tag << endl;
	// }
	queue<int> que;
	que.push(1);
	while (!que.empty()) {
		int sz = que.size();
		for (int i=0; i<sz; i++) {
			int u = que.front(); que.pop();
			Seg t = sg[u];
			cout << "{" << u << " [" << t.l << ", " << t.r << "] pre:" << t.pre << " sfx:" << t.sfx << " sum:" << t.sum << " max:" << t.max <<"} ";
			if (sg[u<<1].l) que.push(u<<1);
			if (sg[u<<1|1].l) que.push(u<<1|1);
		}
		cout << endl;
	}
}

void sol() {
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sg_build(1, 1, n);
	// sg_print();
	for (int i=0; i<m; i++) {
		int opt, x, y;
		cin >> opt >> x >> y;
		if (opt == 1) {
			if (x > y) swap(x, y);
			cout << sg_query(1, x, y).max << endl;
		} else {
			sg_update(1, x, y);
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