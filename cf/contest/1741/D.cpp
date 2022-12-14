#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];

int dfs(int l, int r, int mask) {
	if (mask == 0) return 0;
	int m = l+r>>1;
	int v = mask&a[l];
	for (int i=l; i<m; i++) if ((mask&a[i]) != v) return -1;
	int rt = v?1:0;
	int ls = dfs(l, m, mask>>1);
	int rs = dfs(m, r, mask>>1);
	if (ls==-1 || rs==-1) return -1;
	return ls+rs+rt;
}

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		a[i]--;
	}
	cout << dfs(0, n, n>>1) << "\n";
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