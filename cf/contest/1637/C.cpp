#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int a[100005];

bool allone() {
	for (int i=1; i<n-1; i++) {
		if (a[i] != 1) return false;
	}
	return true;
}


void sol() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	if (allone() || n==3 && a[1]%2) {
		cout << "-1" << "\n";
		return ;
	}
	ll ans = 0;
	for (int i=1; i<n-1; i++) {
		ans += a[i]/2;
		if (a[i]%2) ans++;
	}
	cout << ans << '\n';
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