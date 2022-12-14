#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
	int n; cin >> n;
	std::vector<ll> v(n);
	for (int i=0; i<n; i++) {
		cin >> v[i];
		if (i>0) cout << v[i]-v[i-1] << " ";
		else cout << v[i] << " ";
	}
	cout << endl;

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