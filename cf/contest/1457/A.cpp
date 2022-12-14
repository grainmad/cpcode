#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;


void sol() {
	ll n, m, r, c;
	cin >> n >> m >> r >> c;
	cout << max(abs(r-1), abs(r-n)) + max(abs(c-1), abs(c-m)) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
	return 0;
}