#include <bits/stdc++.h>
using namespace std;


void sol() {
	int l, r, k;
	cin >> l >> r >> k;
	if (l == r && l != 1) {
		cout << "YES" << '\n';
	} else if (l%2 && r%2) {
		cout << (k>=(r-l+1)/2+1 ? "YES":"NO") << '\n';
	} else cout << (k>=(r-l+1)/2 ? "YES":"NO") << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
