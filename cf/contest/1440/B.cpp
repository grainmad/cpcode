#include <bits/stdc++.h>
#define ll long long
#define N 1000005
using namespace std;

void sol() {
	int n, k;
	cin >> n >> k;
	std::vector<int> v(n*k);
	for (int& i:v) cin >> i;
	sort(v.rbegin(), v.rend());
	ll ans = 0;
	for (int i=n-(n+1)/2, j=0; j<k; j++) {
		// cout << i << ", ";
		ans += v[i];
		i += n-(n+1)/2+1;
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
	return 0;
}