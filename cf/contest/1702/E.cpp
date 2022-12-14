#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;


/*
不能有奇数条边组成的环
*/

int st[N];
int cnt[N];

int ufind(int x) {
	if (st[x] < 0) return x;
	return st[x] = ufind(st[x]);
}

void sol() {
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		st[i] = -1;
		cnt[i] = 0;
	}
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		cnt[x]++; cnt[y]++;
		int fx = ufind(x), fy = ufind(y);
		if (fx != fy) {
			st[fx] += st[fy];
			st[fy] = fx;
		}
	}
	int ok = 1;
	for (int i=1; i<=n; i++) {
		if (st[i]<0 && (-st[i])%2) ok = 0;
		if (cnt[i] != 2) ok = 0;
	}
	cout << (ok?"YES":"NO") << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef SINGLE_INPUT
	int t;
	cin >> t;
	while (t--) sol();
#else
	sol();
#endif
	return 0;
}