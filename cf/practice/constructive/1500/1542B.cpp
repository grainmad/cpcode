//11:07 11:55
#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;


void sol() {
	ll n, a, b;
	cin >> n >> a >> b;
	if (a == 1) {
		cout << ((n-1)%b ? "NO":"YES") << '\n';
	} else {
		ll t = 1;
		while (t <= n) {
			if ((n-t)%b == 0) {
				break;
			}
			t*=a;
		}
		cout << (t<=n ? "YES":"NO") << '\n';
	}
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
}