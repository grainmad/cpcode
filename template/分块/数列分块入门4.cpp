#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
#define M 350
using namespace std;
/*
#6280. 数列分块入门 4
区间修改，区间求和
*/

int n;
ll a[N];
int L[M], R[M], B[N];
ll sum[M], tag[M];
int s, sz;
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
	}
}

void add(int l, int r, ll val) {
	int x = B[l], y = B[r];
	if (x == y) {
		for (int i=l; i<=r; i++) {
			a[i] += val;
			sum[x] += val;
		}
	} else {
		for (int i=l; i<=R[x]; i++) {
			a[i] += val;
			sum[x] += val;
		}
		for (int i=L[y]; i<=r; i++) {
			a[i] += val;
			sum[y] += val;
		}
		for (int i=x+1; i<y; i++) {
			tag[i] += val;
		}
	}
}

ll ask(int l, int r, ll c) {
	int x = B[l], y = B[r];
	ll rt = 0;
	if (x == y) {
		for (int i=l; i<=r; i++) {
			rt += a[i] + tag[x];
		}
	} else {
		for (int i=l; i<=R[x]; i++) {
			rt += a[i] + tag[x];
		}
		for (int i=L[y]; i<=r; i++) {
			rt += a[i] + tag[y];
		}
		for (int i=x+1; i<y; i++) {
			rt += sum[i] + tag[i]*s;
		}
	}
	return rt%c;
}

void sol() {
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	init();
	for (int i=1; i<=n; i++) {
		ll opt, l, r, c;
		cin >> opt >> l >> r >> c;
		if (opt) {
			cout << ask(l, r, c+1) << endl;
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