#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	for (int i=0; i<n; i++) {
		if (a[i] == 'G' || a[i] == 'B') a[i] = '*';
		if (b[i] == 'G' || b[i] == 'B') b[i] = '*';
	}
	cout << (a==b?"YES\n":"NO\n");
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