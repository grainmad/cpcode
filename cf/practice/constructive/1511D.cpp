#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int m[26] = {0};

void sol() {
	int n, k;
	cin >> n >> k;
	char o = 'a'+k-1;
	cout << o;
	for (int i=1; i<n; i++) {
		o = 'a'+((m[o-'a']++)%k);
		cout << o;
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