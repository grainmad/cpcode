#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 50
using namespace std;

ll a[N];

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	int cnt = 0;
	for (int i=n-2; i>=0; i--) {
		if (a[i+1] == 0) {
			cnt = -1;
			break;
		}
		while (a[i] >= a[i+1]) {
			a[i] /= 2;
			cnt++;
		}
	}
	cout << cnt << endl;
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