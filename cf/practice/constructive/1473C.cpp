#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];

void sol() {
	int n, k;
	cin >> n >> k;
	for (int i=1; i<=k; i++) {
		a[i] = i;
	}
	int l = 2*k-n, r = k;
	while (l<r) {
		swap(a[l], a[r]);
		l++; r--;
	}
	for (int i=1; i<=k; i++) {
		cout << a[i] << " ";
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