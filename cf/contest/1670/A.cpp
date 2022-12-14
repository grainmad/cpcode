#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

ll a[N];

void sol() {
	int n, neg = 0;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (a[i]<0) neg++;
		a[i] = abs(a[i]);
	}
	for (int i=0; i<neg; i++) {
		a[i] = -a[i];
	}
	cout << (is_sorted(a, a+n)?"YES":"NO") << endl;

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