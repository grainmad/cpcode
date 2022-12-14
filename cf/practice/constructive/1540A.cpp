//11:57 12:33
#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int n;
ll a[N];
ll b[N];
void sol() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	b[0] = a[0];
	for (int i=1; i<n; i++) {
		b[i] = b[i-1]+a[i];
	}
	ll ans = 0;
	for (int i=2; i<n; i++) {
		ans += (i-1)*a[i]-b[i-2];
	}
	cout << -ans << '\n';
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