#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int l = 0, r = n-1, cnt = 0;
	while (l<r) {
		while (l<r && a[r] == 1) r--;
		while (l<r && a[l] == 0) l++;
		if (l != r) {
			swap(a[l], a[r]);
			cnt++;
		}
	}
	cout << cnt << "\n";
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