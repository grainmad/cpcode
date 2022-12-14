#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

ll a[N];

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	if (n == 1 && a[0] > 1) {
		cout << "NO\n";
		return ;
	} 
	sort(a, a+n);
	if (a[n-1]-a[n-2] <= 1) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
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