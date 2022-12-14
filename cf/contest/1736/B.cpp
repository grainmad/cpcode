#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 100005
using namespace std;

int a[N];

int gcd(int a, int b) {
	return a==0?b:gcd(b%a, a);
}

int lcm(int a, int b) {
	return a*b/gcd(a, b);
}

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	int ok = 1;
	for (int i=1; i<n-1; i++) {
		if (gcd(lcm(a[i-1], a[i]), lcm(a[i], a[i+1]))!=a[i]) {
			ok = 0;
			break;
		}
	}
	cout << (ok?"YES\n":"NO\n");
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