#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
#define M 350
using namespace std;
/*
#6278. 数列分块入门 2
区间修改，区间查询符合条件的值
*/

int n;
ll a[N];

int L[N], R[N], B[N], BL[M], BR[M];
ll tag[M], b[N]; 
int s, sz;
/*
L[i] 索引i所属块的左端
R[i] 索引i所属块的右端
BL[i] 块i所属的左端
BR[i] 块i所属的右端
B[i] 索引i所属块
tag[i] 块i的懒标记
b 将a在每一块进行排序，方便二分查找
*/

void init() {
	s = sqrt(n);
	sz = (n+s-1)/s;
	for (int i=1; i<=n; i++) {
		b[i] = a[i];
		B[i] = (i-1)/s+1;
		L[i] = (B[i]-1)*s+1;
		R[i] = min(n, B[i]*s);
	}
	for (int i=1; i<=sz; i++) {
		BL[i] = (i-1)*s+1;
		BR[i] = min(n, i*s);
		sort(b+BL[i], b+BR[i]+1);
	}
	// for (int i=1; i<=n; i++) {
	// 	cout << a[i] << " " << b[i] << endl;
	// }
}

void add(int l, int r, ll val) {
	int x = B[l], y = B[r];
	if (x == y) {
		for (int i=l; i<=r; i++) {
			a[i] += val;
		}
		for (int i=BL[x]; i<=BR[x]; i++) {
			b[i] = a[i];
		}
		sort(b+BL[x], b+BR[x]+1);
	} else {
		for (int i=l; i<=R[l]; i++) {
			a[i] += val;
		}
		for (int i=BL[x]; i<=BR[x]; i++) {
			b[i] = a[i];
		}
		sort(b+BL[x], b+BR[x]+1);

		for (int i=L[r]; i<=r; i++) {
			a[i] += val;
		}
		for (int i=BL[y]; i<=BR[y]; i++) {
			b[i] = a[i];
		}
		sort(b+BL[y], b+BR[y]+1);

		for (int i=x+1; i<y; i++) {
			tag[i]+=val;
		}
	}
}

int ask(int l, int r, ll val) {
	int rt = 0;
	int x = B[l], y = B[r];
	if (x == y) {
		for (int i=l; i<=r; i++) {
			if (val > a[i]+tag[x]) rt++;
		}
	} else {
		for (int i=l; i<=R[l]; i++) {
			if (val > a[i]+tag[x]) rt++;
		}

		for (int i=L[r]; i<=r; i++) {
			if (val > a[i]+tag[y]) rt++;
		}

		for (int i=x+1; i<y; i++) {
			int ge = lower_bound(b+BL[i], b+BR[i]+1, val-tag[i])-b-BL[i];
			rt += ge;
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
	for (int i=0; i<n; i++) {
		int opt, l, r, c;
		cin >> opt >> l >> r >> c;
		if (opt) {
			cout << ask(l, r, c*c) << endl;
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