//C
#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N 105
using namespace std;

ll k[N], h[N];
ll dp[N];


void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> k[i];
	for (int i=0; i<n; i++) cin >> h[i];
	std::vector<pair<ll,ll>> st;
	for (int i=0; i<n; i++) {
		st.push_back({k[i]-h[i], k[i]});
	}
	sort(st.begin(), st.end());
	ll ans = 0;
	ll l = -1, r = -1;
	for (int i=0; i<n; i++) {
		if (st[i].first >= r) {
			ans += (r-l)*(r-l+1)/2;
			l = st[i].first;
			r = st[i].second;
		} else {
			r = max(r, st[i].second);
		}
	}
	ans += (r-l)*(r-l+1)/2;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}