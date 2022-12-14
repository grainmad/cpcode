#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;
	

bool j() {
	for (int i=0; i<n/2; i++) {
		if (s[i] != s[n-1-i]) return false;
	}
	return true;
}

void sol() {
	cin >> n >> k;
	cin >> s;
	if (!j() && k>=1) cout << 2 << endl;
	else cout << 1 << endl;
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