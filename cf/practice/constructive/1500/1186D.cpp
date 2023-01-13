#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

double a[N];

// bool is_int(double x) {
// 	return fabs(x)-int(fabs(x)) < 1e-9;
// }

// int myfloor(double x) {
// 	bool sign = x<0;
// 	int ab = fabs(x);
// 	if (is_int(x)) return sign?-ab:ab;
// 	if (sign) return -(1+ab);
// 	return ab;
// }

// int myceil(double x) {
// 	bool sign = x<0;
// 	int ab = fabs(x);
// 	if (is_int(x)) return sign?-ab:ab;
// 	if (sign) return -ab;
// 	return ab+1;
// }

void sol() {
	int n;
	cin >> n;
	ll fsum=0;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		fsum += floor(a[i]);
		// cout << floor(a[i]) << " ";
	}
	// cout << "\n";
	for (int i=0; i<n; i++) {
		if (ceil(a[i]) == floor(a[i])) {
			cout << a[i] << "\n";
		} else {
			if (fsum<0) {
				fsum++;
				cout << int(ceil(a[i])) << "\n";
			} else {
				cout << int(floor(a[i])) << "\n";
			}
		}
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