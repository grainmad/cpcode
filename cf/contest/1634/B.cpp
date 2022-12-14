#include <bits/stdc++.h>

using namespace std;

int n, t;
long long x, y;

void sol() {
	cin >> n >> x >> y;
	for (int i=0; i<n; i++) {
		cin >> t;
		x^=t;
	}
	if (x%2 == y%2) cout << "Alice\n";
	else cout << "Bob\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		sol();
	}
	return 0;
}
