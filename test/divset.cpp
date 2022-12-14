#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 25
using namespace std;

int n;
int a[N];
bool vis[N];

//返回true，找到一个和为k的子集
bool dfs(int p, int cnt, int k) {
	if (cnt == k) return true;
	for (int i=p; i<n; i++) {
		if (vis[i] == 0 && cnt+a[i] <= k) {
			vis[i] = 1;
			if (dfs(i+1, cnt+a[i], k)) return true;
			vis[i] = 0;
		}
	}
	return false;
}

//每组和为k是否能分成
bool ok(int k) {
	cout << k << ":" << endl;
	memset(vis, 0, sizeof(vis));
	for (int i=0; i<n/k; i++) {//每次dfs都要能找出一个和为k的子集
		if (!dfs(0, 0, k)) return false;
		for (int j=0; j<n; j++) cout << vis[j] << " "; cout << endl;
	}
	return true;
}

void sol() {
	int sum = 0;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a+n, [](auto x, auto y) {
		return x > y;
	});
	for (int i=0; i<n; i++) {
		cout << a[i] << " ";
	} cout << endl;
	cout << sum  << endl;
	for (int i=2, sz=sqrt(sum); i<=sz; i++) {
		if (sum%i == 0) {
			if (ok(sum/i)) {
				cout << sum/i << endl;
				break;
			}
			if (ok(i)) {
				cout << i << endl;
				break;
			}
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