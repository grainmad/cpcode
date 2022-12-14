#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
#define M 350
#define MOD 10007
using namespace std;

int a[N];
int n;

int L[M], R[M], B[N];
ll tag_add[M], tag_mul[M];
int s, sz;
void init() {
	s = sqrt(n);
	sz = (n+s-1)/s;
	for (int i=1; i<=n; i++) {
		B[i] = (i-1)/s+1;
	}
	for (int i=1; i<=sz; i++) {
		L[i] = (i-1)*s+1;
		R[i] = min(n, i*s);
		tag_add[i] = 0;
		tag_mul[i] = 1;
	}
}

void push_down(int x) {
	for (int i=L[x]; i<=R[x]; i++) {
		a[i] = ((a[i]*tag_mul[x]%MOD+tag_add[x])%MOD+MOD)%MOD;
	}
	tag_add[x] = 0; tag_mul[x] = 1;
}

void add(int l, int r, ll val) {
	int x = B[l], y = B[r];
	if (x == y) {
		push_down(x);		
		for (int i=l; i<=r; i++) {
			a[i] = ((a[i]+val)%MOD+MOD)%MOD;
		}
	} else {
		push_down(x);
		for (int i=l; i<=R[x]; i++) {
			a[i] = ((a[i]+val)%MOD+MOD)%MOD;
		}

		push_down(y);
		for (int i=L[y]; i<=r; i++) {
			a[i] = ((a[i]+val)%MOD+MOD)%MOD;
		}
		
		for (int i=x+1; i<y; i++) {
			tag_add[i] += val; tag_add[i] %= MOD;
		}
	}
}

void mul(int l, int r, ll val) {
	int x = B[l], y = B[r];
	if (x == y) {
		push_down(x);
		for (int i=l; i<=r; i++) {
			a[i] = ((a[i]*val)%MOD+MOD)%MOD;
		}
	} else {
		push_down(x);
		for (int i=l; i<=R[x]; i++) {
			a[i] = ((a[i]*val)%MOD+MOD)%MOD;
		}
		push_down(y);
		for (int i=L[y]; i<=r; i++) {
			a[i] = ((a[i]*val)%MOD+MOD)%MOD;
		}
		for (int i=x+1; i<y; i++) {
			tag_add[i] *= val; tag_add[i] %= MOD;
			tag_mul[i] *= val; tag_mul[i] %= MOD;
		}
	}
}

ll ask(int x) {
	return ((a[x] * tag_mul[B[x]] % MOD + tag_add[B[x]])%MOD+MOD)%MOD;
}

void sol() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		// a[i] = (a[i]%MOD+MOD)%MOD;
	}
	init();
	for (int i=1; i<=n; i++) {
		int opt, l, r, c;
		cin >> opt >> l >> r >> c;
		if (opt == 2) {
			cout << ask(r) << endl;
		} else if (opt == 1) {
			mul(l, r, c);
		} else {
			add(l, r, c);
		}
	}
}

int main() {
	// freopen("a2.in", "r", stdin);
	// freopen("a2.out", "w", stdout);
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