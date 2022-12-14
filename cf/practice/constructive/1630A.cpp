#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];

void sol() {
	int n, k;
	cin >> n >> k;
	for (int i=0; i<n; i++) a[i] = i;
	if (n == 4 && k == n-1) {cout << "-1\n"; return ;}
	if (k == n-1) {
		swap(a[0], a[n-2]);
		swap(a[n-2], a[n-3]);
	} else {
		swap(a[0], a[k]);	
	}
	for (int i=0; i<n/2; i++) {
		cout << a[i] << " " << a[n-i-1] << "\n";
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