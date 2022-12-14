#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MAXN 1000005
#define MOD 998244353
using namespace std;

bool nprime[MAXN];
vector <int> prime;


void get_prime() {
	memset(nprime, 0, sizeof(nprime));
	int n = (int) sqrt(MAXN+0.5);
	for (int i=2; i<n; i++) {
		if (!nprime[i]) {
			for (int j=i*i; j<MAXN; j+=i) {
				nprime[j] = true;
			}
		}
	}
	for (int i=2; i<MAXN; i++) {
		if (!nprime[i]) {
			prime.push_back(i);
			// cout << i << endl;
		}
	}
}


void sol() {
	get_prime();
	ll k; cin >> k;
	ll ans = 1;
	for (int i:prime) {
		if (k%i) continue;
		ll c = 0;
		while (k%i == 0) {
			k/=i;
			c++;
		}
		ans = max(ans, c*i);
	}
	if (k != 1) ans = max(ans, k);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef SINGLE_INPUT
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
#else
	sol();
#endif
	return 0;
}