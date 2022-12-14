#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

std::vector<ll> v;


void sol() {
	ll n, ans = 40;
	cin >> n;
	int sz = 1<<v.size();
	for (int i=0; i<sz; i++) {
		ll fc = 0, cnt=0;
		for (int j=0; j<14; j++) {
			if ((i>>j)&1) {
				fc += v[j];
				cnt++;
			}
		}
		if (fc > n) continue;
		ll p = n-fc;
		while (p) {
			if (p&1) {
				cnt++;
			}
			p>>=1;
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
}

int main() {
	ll p = 1;
	for (int i=1; i<50; i++) {
		if (p*i <= 1e12) {
			p = p*i;
			v.push_back(p);
		} 
	}
	// cout << v.size();
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
	// sol();
}