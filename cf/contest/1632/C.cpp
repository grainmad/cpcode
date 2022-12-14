#include <bits/stdc++.h>

using namespace std;


void sol() {
	int a, b, cnt = 0;
	cin >> a >> b;
	if ((a|b)-b+1>b-a) cout << b-a << endl;
	else cout << ((a|b)-b+1) << endl;
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