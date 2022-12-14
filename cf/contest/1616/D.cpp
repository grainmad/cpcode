#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;


void sol() {
	ll n, x;
	cin >> n;
	std::vector<ll> v(n);
	for (auto& i:v) cin >> i;
	cin >> x;
	for (auto& i:v) i-=x;
	int p = -1, ans = n;
	for (int i=0; i<n; i++) {
		bool ok = true;
		if (i>=p+2 && i>=1 && v[i]+v[i-1]<0) ok = false;
		if (i>=p+3 && i>=2 && v[i]+v[i-1]+v[i-2]<0) ok = false;
		if (!ok) {
			ans--;
			p = i;
		}
	}
	cout << ans << "\n";
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