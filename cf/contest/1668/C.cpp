#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 5005
using namespace std;

int a[N];

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	ll ans = 1e17;
	for (int i=0; i<n; i++) {
		ll cnt = 0;
		ll cur = 0;
		for (int j=i-1; j>=0; j--) {
			cnt += cur/a[j]+1;
			cur = (cur/a[j]+1)*a[j];
		}
		cur = 0;
		for (int j=i+1; j<n; j++) {
			cnt += cur/a[j]+1;
			cur = (cur/a[j]+1)*a[j];	
		}
		ans = min(ans, cnt);
	}
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