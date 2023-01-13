#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int a, cnt = 0;
	cin >> a;
	int u = a;
	while (u) {
		u>>=1;
		cnt++;
	}
	int v = (1<<cnt)-1;
	if (v == a) {
		int sz = sqrt(v);
		for (int i=2; i<=sz; i++) {
			if (v%i==0) {
				cout << v/i << "\n";
				return;
			}
		}
		cout << "1\n";
	}
	else cout << v << "\n";
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