#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 5005
using namespace std;

int a[N];


void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	for (int i=1; i<n; i++) {
		if (a[i]==a[i-1]) {
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
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