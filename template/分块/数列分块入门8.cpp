#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
#define M 350
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

ll a[N];
int L[M], R[M], B[N];
ll tag[M];
int n, sz, s;


void push_down(int x) {
	if (tag[x] != INF) {
		for (int i=L[x]; i<=R[x]; i++) {
			a[i] = tag[x];
		}
		tag[x] = INF;
	}
}

void init() {
	s = sqrt(n);
	sz = (n+s-1)/s;
	for (int i=1; i<=n; i++) {
		B[i] = (i-1)/s+1;
	}
	for (int i=1; i<=sz; i++) {
		L[i] = (i-1)*s+1;
		R[i] = min(n, i*s);
		tag[i] = INF;
	}
}

ll ask(int l, int r, ll val) {
	int x = B[l], y = B[r];
	ll rt = 0;
	if (x == y) {
		push_down(x);
		for (int i=l; i<=r; i++) {
			if (val == a[i]) rt++;
			a[i] = val;
		}
	} else {
		push_down(x);
		for (int i=l; i<=R[x]; i++) {
			if (val == a[i]) rt++;
			a[i] = val;
		}
		push_down(y);
		for (int i=L[y]; i<=r; i++) {
			if (val == a[i]) rt++;
			a[i] = val;
		}
		for (int i=x+1; i<y; i++) {
			if (tag[i] == val) rt += s;
			else if (tag[i] == INF) {
				for (int j=L[i]; j<=R[i]; j++) {
					if (val == a[j]) rt++;
					a[j] = val;
				}
			}
			tag[i] = val;
		}
	}
	return rt;
}

void sol() {
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	init();
	for (int i=1; i<=n; i++) {
		int l, r, c;
		cin >> l >> r >> c;
		cout << ask(l, r, c) << "\n";
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