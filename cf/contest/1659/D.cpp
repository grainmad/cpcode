#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define ls (id<<1)
#define rs (id<<1|1)
#define N 200005
using namespace std;
//线段树版本
int a[N];
ll k;

struct Seg {
	int l, r;
	int val, tag;
} seg[N<<2];

void seg_build(int id, int l, int r) {
	seg[id] = {l, r, 0, 0};
	if (l == r) {
		cin >> seg[id].val;
		k += seg[id].val;
		return;
	}
	int m = l+r>>1;
	seg_build(ls, l, m);
	seg_build(rs, m+1, r);
}

void push_down(int id) {
	if (seg[id].tag != 0) {
		seg[ls].tag += seg[id].tag;
		seg[rs].tag += seg[id].tag;
		seg[id].tag = 0;
	}
}

void seg_update(int id, int l, int r) {//减一
	if (l <= seg[id].l && seg[id].r <= r) {
		seg[id].tag--;
		return ;
	}
	push_down(id);
	int m = seg[id].l+seg[id].r>>1;
	if (l <= m) seg_update(ls, l, r);
	if (m < r) seg_update(rs, l, r);
}

int seg_query(int id, int p) {
	if (p == seg[id].l && seg[id].r == p) {
		return seg[id].tag+seg[id].val;
	}
	push_down(id);
	int m = seg[id].l+seg[id].r>>1;
	if (p <= m) return seg_query(ls, p);
	else return seg_query(rs, p);
}


void sol() {
	int n;
	cin >> n;
	k = 0;
	seg_build(1, 1, n);
	k /= n;
	for (int i=n; i>0; i--) {
	  	ll v = seg_query(1, i);
		if (v == i) {
			a[i] = 1;
			seg_update(1, i-k+1, i);
			k--;
		} else {
			a[i] = 0;
			seg_update(1, i-k+1, i);
		}
	}
	for (int i=1; i<=n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
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