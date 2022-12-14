#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

ll a[N];

void sol() {
	int n;
	cin >> n;
	ll flag = 0;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (a[i]%5==0) {
			flag = 1;
			a[i] += a[i]%10;
		}
	}
	if (flag) {
		cout << (count(a, a+n, a[0])==n ? "YES\n":"NO\n");
		return ;
	}
	for (int i=0; i<n; i++) {
		while (a[i]%10 != 2) a[i]+=a[i]%10;
	}
	int ok = 1;
	for (int i=1; i<n; i++) {
		if (abs(a[i]-a[0])%20 !=0) {
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