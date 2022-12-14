#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

bool is_prime(int x) {
	for (int i=2, sz=sqrt(x); i<=sz; i++) {
		if (x%i == 0) {
			return false;
		}
	}
	return true;
}

void sol() {
	int n;
	cin >> n;
	int pr = n;
	for (int i=n; i<n+n/2; i++) {
		if (is_prime(i)) {
			pr = i;
			break;
		}
	}
	int b = (pr-n)*2, a = n-b;
	cout << b*3/2+a << "\n";
	for (int i=0; i<n; i++) {
		cout << i+1 << " " << (i+1)%n+1 << "\n";
	}
	for (int i=0; i<b/2; i++) {
		cout << i+1 << " " << i+n/2+1 << "\n";
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