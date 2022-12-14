#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

int a[N];

void sol() {
	int n, k; cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=k; i<n; i++) {
		cout << a[i] << " ";
	}
	for (int i=0; i<min(k, n); i++) {
		cout << "0 ";
	}
	cout << "\n";
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