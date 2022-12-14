#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

ll s[N];

void sol() {
	int n, k;
	cin >> n >> k;
	for (int i=0; i<k; i++) {
		cin >> s[i];
	}
	if (k == 1) {
		cout << "YES\n";
		return ;
	}
	std::vector<ll> v;
	for (int i=1; i<k; i++) {
		v.push_back(s[i]-s[i-1]);
	}
	for (int i=1; i<v.size(); i++) {
		if (v[i-1]>v[i]) {
			cout << "NO\n";
			return ;
		}
	}
	if ((n-k+1)*v[0] < s[0]) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
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