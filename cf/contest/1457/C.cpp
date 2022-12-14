#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int cnt[N];
int need[N];

void sol() {
	int n, p, k;
	ll x, y;
	string s;
	cin >> n >> p >> k;
	for (int i=0; i<n+3; i++) {
		cnt[i] = need[i] = pos[i] = 0;
	}
	cin >> s;
	cin >> x >> y;
	for (int i=n; i>=p; i--) {
		if (s[i-1] == '1') cnt[i] = 1;
		if (i+k<=n) {
			cnt[i] += cnt[i+k];
			need[i] = need[i+k]+1;
		} else {
			need[i] = 1;
		}
	}
	// for (int i=1; i<=n; i++) {
	// 	cout << cnt[i] << " ";
	// }cout << endl;
	// for (int i=1; i<=n; i++) {
	// 	cout << need[i] << " ";
	// }cout << endl;
	// for (int i=1; i<=n; i++) {
	// 	cout << pos[i] << " ";
	// }cout << endl;
	ll mn = 1e15, dlt = 0;
	for (int i=p; i<=n; i++) {
		mn = min(mn, dlt+(need[i]-cnt[i])*x);
		dlt += y;
	}
	cout << mn << endl;
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