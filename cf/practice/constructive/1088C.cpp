#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 2005
using namespace std;

ll a[N];

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	cout << n+1 << endl;
	// for (int i=n-1; i>=0; i--) {
	// 	ll add = n-a[i]%n+i;
	// 	cout << 1 << " " << i+1 << " " << add << endl;
	// 	for (int j=i; j>=0; j--) {
	// 		a[j] += add;
	// 	}
	// }
	// cout << 2 << " " << n << " " << n << endl;
	cout << "1 " << n << " " << 500000 << endl;
	for (int i=0; i<n; i++) {
		a[i]+=500000;
		cout << 2 << " " << i+1 << " " << a[i]-i << endl;
		a[i]%=(a[i]-i);
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