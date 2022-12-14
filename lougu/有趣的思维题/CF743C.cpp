#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;


void sol() {
	int n;
	cin >> n;
	if (n == 1) cout << -1;
	else {
		cout << n << " " << n+1 << " " << n*(n+1) << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// int t;
	// cin >> t;
	// while (t--) {
	// 	sol();
	// }
	sol();
	return 0;
}