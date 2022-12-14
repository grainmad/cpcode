#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 100005
using namespace std;

/*
a 全部置为 1
第 i 次操作为1，则将a[i] = m, 查询区间和[1, Q]
第 i 次操作为2，则将a[pos] = 1，查询区间和[1, Q]

有多组数据

*/

ll m[N];

ll Q, M;

struct Seg{
	int l, r;
	ll val;
} sg[N<<2];

void push_up(int id) {
	sg[id].val = sg[id<<1].val*sg[id<<1|1].val%M;
}


void sg_build(int id, int l, int r) {
	sg[id].l = l; sg[id].r = r;
	if (l == r) {
		sg[id].val = 1;
		return ;
	}
	int m = l+r>>1;
	sg_build(id<<1, l, m);
	sg_build(id<<1|1, m+1, r);
	push_up(id);
}

void sg_update(int id, int p, ll val) {
	if (p == sg[id].l && sg[id].r == p) {
		sg[id].val = val;
		return ;
	}
	int m = sg[id].l+sg[id].r>>1;
	if (p <= m) sg_update(id<<1, p, val);
	if (m < p) sg_update(id<<1|1, p, val);
	push_up(id);
}

ll sg_query(int id, int l, int r) {
	if (l <= sg[id].l && sg[id].r <= r) {
		return sg[id].val;
	}
	ll rt = 1;
	int m = sg[id].l + sg[id]. r >> 1;
	if (l <= m) rt = rt*sg_query(id<<1, l, r)%M;
	if (m < r) rt = rt*sg_query(id<<1|1, l, r)%M;
	return rt;
}


void sg_print() {
	for (int i=1; i<(N<<2); i++) {
		if (sg[i].l != 0)
		cout << "id:" << i << " [" << sg[i].l << "," << sg[i].r << "] val:" << sg[i].val << endl;
	}
}


void sol() {
	cin >> Q >> M;
	sg_build(1, 1, Q);
	// sg_print();
	for (int i=1; i<=Q; i++) {
		int opt;
		cin >> opt >> m[i];
		if (opt == 1) {
			sg_update(1, i, m[i]);
		} else {
			sg_update(1, m[i], 1);
		}
		// sg_print();
		// cout << endl;
		cout << sg_query(1, 1, Q) << endl;
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