#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int a[105];

void sol() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		if (a[i] == 0) a[i] = 2;
		else a[i] = 1;
	}
	for (int i=1; i<=n; i++) {
		a[i] += a[i-1];
	}
	int ans = 0;
	for (int i=1; i<=n; i++) {
		for (int j=0; j+i<=n; j++) {
			ans += a[j+i]-a[j];
		}
	}
	cout << ans << endl;
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