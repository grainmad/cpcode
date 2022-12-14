#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	std::vector<ll> a(n), b(n);
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		a[i] = x;
		b[i] = y;
	}
	cout << 2*(accumulate(a.begin(), a.end(), 0LL)+*max_element(b.begin(), b.end())) << endl;

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