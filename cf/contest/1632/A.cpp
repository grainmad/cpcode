#include <bits/stdc++.h>

using namespace std;


char s[105];

void sol() {
	int n;
	cin >> n;
	cin >> s;
	if (n==1 || n == 2 && s[0] != s[1]) cout << "YES" << endl;
	else cout << "NO" << endl;
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