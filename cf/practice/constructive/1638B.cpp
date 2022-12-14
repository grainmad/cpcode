#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;



void sol() {
	string cf = "codeforces";
	ll n;
	cin >> n;
	ll cur = 1, c = 10;
	while (cur < n) {
		cur /= c/10;
		cur *= c/10+1;
		c++;
	}
	for (int i=0; i<10; i++) {
		for (int j=0; j<(c/10+(i<c%10?1:0)); j++) {
			cout << cf[i];
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