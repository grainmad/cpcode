#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
#define M 350
using namespace std;
/*
#6281. 数列分块入门 5
2^32 开方6次就会恒定为1
对于一个完整的分块的修改不会超过6次
*/

int n;
ll a[N];
int L[M], R[M], B[N];
ll sum[M], tag[M];
int s, sz;
/*
tag[i] 块i是否失效
*/


void change(int x) {
	tag[x] = 1;
	for (int i=L[x]; i<=R[x]; i++) {
		if (a[i]>1) tag[x] = 0;
	}
}

void init() {
	s = sqrt(n);
	sz = (n+s-1)/s;
	for (int i=1; i<=n; i++) {
		B[i] = (i-1)/s+1;
		sum[B[i]] += a[i];
	}
	for (int i=1; i<=sz; i++) {
		L[i] = (i-1)*s+1;
		R[i] = min(n, i*s);
		change(i);
	}
}


void update(int l, int r) {
	int x = B[l], y = B[r];
	if (x == y) {
		// O(n^(1/2))
		if (!tag[x]) {
			for (int i=l; i<=r; i++) {
				sum[x] -= a[i];
				a[i] = sqrt(a[i]);
				sum[x] += a[i];
			}
			change(x);	
		}
	} else {
		// O(n^(1/2))
		if (!tag[x]) {
			for (int i=l; i<=R[x]; i++) {
				sum[x] -= a[i];
				a[i] = sqrt(a[i]);
				sum[x] += a[i];
			}
			change(x);	
		}
		if (!tag[y]) {
			for (int i=L[y]; i<=r; i++) {
				sum[y] -= a[i];
				a[i] = sqrt(a[i]);
				sum[y] += a[i];
			}
			change(y);	
		}
		// O(n) -> O(n^(1/2))
		for (int i=x+1; i<y; i++) {
			if (!tag[i]) {//虽然每块的更新是暴力，但不会超过6次
				sum[i] = 0;
				for (int j=L[i]; j<=R[i]; j++) {
					a[j] = sqrt(a[j]);
					sum[i] += a[j];
				}
				change(i);
			}
		}
	}
}

ll query(int l, int r) {
	int x = B[l], y = B[r];
	ll rt = 0;
	if (x == y) {
		for (int i=l; i<=r; i++) {
			rt += a[i];
		}
	} else {
		for (int i=l; i<=R[x]; i++) {
			rt += a[i];
		}
		for (int i=L[y]; i<=r; i++) {
			rt += a[i];
		}
		for (int i=x+1; i<y; i++) {
			rt += sum[i];
		}
	}
	return rt;
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
			cout << query(l, r) << "\n";
		} else {
			update(l, r);
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