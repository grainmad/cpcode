//22:26 22:58
#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;


void sol() {
	ll n, m, k;
	cin >> n >> m >> k;
	if (m < n-1 || m > (n-1)*n/2 || k < 2) {
		cout << "NO\n";
		return;
	}
	if (k == 2) {
		cout << (n==1?"YES\n":"NO\n");
	} else if (k == 3) {
		cout << (m == n*(n-1)/2?"YES\n":"NO\n");
	} else {
		cout << "YES\n";
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