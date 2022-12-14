#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];

void sol() {
	a[0] = 0;
	int n;
	cin >> n;
	if (n%2) {
		for (int i=1; i<=n; i++) {
			cin >> a[i];
		}
		n++;
	} else {
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
	}
	bool flag = true;
	// for (int i=0; i<n; i++) {
	// 	cout << a[i] << " ";
	// } cout << endl;
	for (int i=1; i<n/2; i++) {
		if (max(a[2*(i-1)], a[2*(i-1)+1]) > min(a[2*i], a[2*i+1]))  {
			flag = false;
			break;
		}
	}
	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;
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