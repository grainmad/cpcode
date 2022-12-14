#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998224353
using namespace std;

int a[N];

void sol() {
	int n, x;
	cin >> n >> x;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) {
		if (a[i] == x) {
			cout << i+1 << endl;
			break;
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