#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	ll cnt = 0;
	for (int i=1; i<=n; i++) {
		if (i+b-c>0 && i+b-c<=n && i+a-d>0 && i+a-d<=n && a-d+b-c+i>0 && a-d+b-c+i<=n) cnt++;
	}
	cout << cnt*n << endl;
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