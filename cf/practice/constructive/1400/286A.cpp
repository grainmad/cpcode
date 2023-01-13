#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];

void sol() {
	int n;
	cin >> n;
	if (n%4 != 1 && n%4 != 0) {
		cout << "-1\n";
		return;
	}
	for (int i=0; i<n/2; i+=2) {
		a[i] = i+2;
		a[i+1] = n-i;
		a[n-i-2] = i+1;
		a[n-i-1] = n-i-1;
	}
	if (n%2) a[n/2] = (n+1)/2;
	for (int i=0; i<n; i++) {
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