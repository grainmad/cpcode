#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

ll a[N];

void sol() {
	int n; string s;
	cin >> n >> s;
	for (int i=0; i<n; i++) {
		if (s[i] == 'L') {
			a[i] = i;
		} else {
			a[i] = n-i-1;
		}
	}
	sort(a, a+n);
	ll sum = accumulate(a, a+n, 0LL);
	for (int i=0; i<n; i++) {
		if (a[i]<n-1-a[i]) sum += n-1-2*a[i];
		cout << sum << " ";
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