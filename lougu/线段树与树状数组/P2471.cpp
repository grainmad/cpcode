#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 50005
using namespace std;


unordered_map<int,int> mp;
ll a[N];

struct Seg{
	int l, r;
	ll val;
} sg[N<<2];

void push_up(int id) {
	sg[id].val = max(sg[id<<1].val, sg[id<<1|1].val);
}

void sg_build(int id, int l, int r) {
	sg[id].l = l; sg[id].r = r;
	if (l == r) {
		sg[id].val = a[l];
		return ;
	}
	int m = l+r>>1;
	sg_build(id<<1, l, m);
	sg_build(id<<1|1, m+1, r);
	push_up(id);
}


ll sg_query(int id, int l, int r) {
	if (l <= sg[id].l && sg[id].r <= r) {
		return sg[id].val;
	}
	ll rt = 0;
	int m = sg[id].l + sg[id]. r >> 1;
	if (l <= m) rt = max(rt, sg_query(id<<1, l, r));
	if (m < r) rt = max(rt, sg_query(id<<1|1, l, r));
	return rt;
}


void sg_print() {
	for (int i=1; i<(N<<2); i++) {
		if (sg[i].l != 0)
		cout << "id:" << i << " [" << sg[i].l << "," << sg[i].r << "] val:" << sg[i].val << endl;
	}
}

void sol() {
	int n, m;
	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x >> a[i];
		mp[x]=i;
	}
	sg_build(1, 1, n);
	// sg_print();
	cin >> m;
	for (int i=0; i<m; i++) {
		int y, x;
		cin >> y >> x;
		if (y>=x) {
			cout << "false" << endl;
			continue;
		}
		if (mp.count(y) && mp.count(x)) {
			if (a[mp[x]] >= a[mp[y]]) cout << "false" << endl;
			else {
				if(y+1==x) cout << "true" << endl;
				else if (sg_query(1, mp[y]+1, mp[x]-1) < a[mp[x]]) {
					if (mp[x]-mp[y] == x-y) cout << "true" << endl;
					else cout << "maybe" << endl;
				} else cout << "false" << endl;
			}
		} else if (mp.count(x)) {
			int p = lower_bound(a+1, a+n+1, y)-a-1;
			int q = mp[x];
			if (y+1==x || sg_query(1, p, q-1) < a[q]) cout << "maybe" << endl;
			else cout << "false" << endl;
		} else if (mp.count(y)) {
			int p = mp[y];
			int q = lower_bound(a+1, a+n+1, x)-a-1;
			if (y+1==x || sg_query(1, p+1, q-1) < a[p]-1) cout << "maybe" << endl;
			else cout << "false" << endl;
		} else {
			cout << "maybe" << endl;
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