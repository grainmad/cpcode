#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
#define M 350
using namespace std;
/*
区间修改，单点查询
*/


int n, s, sz; // n = len(a), s = sqrt(n), sz = (n+s-1)/s
int L[M], R[M], B[N];
ll a[N];
ll tag[M];
/*
L[i] 块i的左端
R[i] 块i的右端
B[i] 索引i所属块的编号
tag[i] 块i的标记
*/

void init() {
	s = sqrt(n);
	sz = (n+s-1)/s;
	for (int i=1; i<=n; i++) {
		B[i] = (i-1)/s+1;
		// cout << i << " bi:" << B[i] << " li:" 
		// << L[i] << " ri:" <<  R[i] << endl;
	}
	for (int i=1; i<=sz; i++) {
		L[i] = (i-1)*s+1;
		R[i] = min(i*s, n);
	}
}

void add(int l, int r, ll val) {
	int x = B[l], y = B[r];
	if (x == y) {
		for (int i=l; i<=r; i++) {
			a[i] += val;
		}
	} else {
		for (int i=l; i<=R[x]; i++) {
			a[i] += val;
		}
		for (int i=x+1; i<y; i++) {
			tag[i]+=val;
		}
		for (int i=L[y]; i<=r; i++) {
			a[i] += val;
		}
	}
}

ll ask(int x) {
	return a[x] + tag[B[x]];
}


void sol() {
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	init();
	for (int i=0; i<n; i++) {
		int opt, l, r, c;
		cin >> opt >> l >> r >> c;	
		if (opt == 0) {
			add(l, r, c);
		} else {
			cout << ask(r) << endl;
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
