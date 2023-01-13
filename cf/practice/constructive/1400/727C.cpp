#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];
int ans[N];

void sol() {
	int n, it=0;
	cin >> n;
	int sz = n%2?n:n-1;
	for (int i=0; i<sz; i++) {
		cout << "? " << i+1 << " " << (i+1)%sz+1 << endl;
		cin >> a[i];
		it = a[i]-it;
	}
	it/=2;
	for (int i=0; i<sz; i++) {
		ans[i] = it;
		it = a[i]-it;
	}
	if (n%2==0) {
		cout << "? 1 " << n << endl;
		int t; cin >> t;
		ans[n-1] = t-ans[0];
	}
	cout << "!";
	for (int i=0; i<n; i++) {
		cout << " " << ans[i];
	}
	cout << endl;
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