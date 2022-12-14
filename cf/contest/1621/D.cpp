#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;


void sol() {
	int n;
	cin >> n;
	ll a = 1e9+7;
	ll b = 0;
	for (int i=0; i<2*n; i++) {
		for (int j=0; j<2*n; j++) {
			ll x;
			cin >> x;
			if (i == 0 && j == n ||
				i == 0 && j == 2*n-1 ||
				i == n-1 && j == n || 
				i == n-1 && j == 2*n-1 ||
				i == n && j == 0 ||
				i == n && j == n-1 ||
				i == 2*n-1 && j == 0 ||
				i == 2*n-1 && j == n-1 
				) {
				a = min(a, x);
			}
			if (n<=i && n<=j) b += x;
		}
	}
	cout << a+b << endl;
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