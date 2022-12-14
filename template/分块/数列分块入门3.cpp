#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define NINF 0xf3f3f3f3f3f3f3f3
#define N 100005
#define M 350
using namespace std;
/*
#6279. 数列分块入门 3
*/

int n;
ll a[N];
int L[M], R[M], B[N];
ll tag[M], b[N];
int s, sz;
/*
L[i] 块i所属左端
R[i] 块i所属右端
B[i] 索引i所属块
tag[i] 块i的懒标记
b[i] 块内有序的a
*/

void init() {
	s = sqrt(n);
	sz = (n+s-1)/s;
	for (int i=1; i<=n; i++) {
		b[i] = a[i];
		B[i] = (i-1)/s+1;
	}
	for (int i=1; i<=sz; i++) {
		L[i] = (i-1)*s+1;
		R[i] = min(n, i*s);
		sort(b+L[i], b+R[i]+1);
	}
}

void add(int l, int r, ll val) {
	int x = B[l], y = B[r];
	if (x == y) {
		for (int i=l; i<=r; i++) a[i] += val;
		for (int i=L[x]; i<=R[x]; i++) b[i] = a[i];
		sort(b+L[x], b+R[x]+1);
	} else {
		for (int i=l; i<=R[x]; i++) a[i] += val;
		for (int i=L[x]; i<=R[x]; i++) b[i] = a[i];
		sort(b+L[x], b+R[x]+1);

		for (int i=L[y]; i<=r; i++) a[i] += val;
		for (int i=L[y]; i<=R[y]; i++) b[i] = a[i];
		sort(b+L[y], b+R[y]+1);

		for (int i=x+1; i<y; i++) tag[i] += val;
	}
}

ll ask(int l, int r, ll val) {
	int x = B[l], y = B[r];
	ll rt = NINF;
	if (x == y) {
		for (int i=l; i<=r; i++) {
			if (a[i]+tag[x] < val) {
				rt = max(rt, a[i]);
			}
		}
	} else {
		for (int i=l; i<=R[x]; i++) {
			if (a[i]+tag[x] < val) {
				rt = max(rt, a[i]+tag[x]);
			}
		}
		for (int i=L[y]; i<=r; i++) {
			if (a[i]+tag[y] < val) {
				rt = max(rt, a[i]+tag[y]);
			}
		}
		for (int i=x+1; i<y; i++) {
			int p = lower_bound(b+L[i], b+R[i]+1, val-tag[i])-b-L[i];
			if (p>0) rt = max(rt, b[L[i]+p-1]+tag[i]);
		}
	}
	return rt == NINF ? -1 : rt;
}

void sol() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	init();
	for (int i=1; i<=n; i++) {
		int opt, l, r, c;
		cin >> opt >> l >> r >> c;
		if (opt) {
			cout << ask(l, r, c) << endl;
		} else {
			add(l, r, c);
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