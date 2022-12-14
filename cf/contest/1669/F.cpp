#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];
void sol() {
	map<int,int> mp;
	int n;
	cin >> n;
	int pre = 0;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		pre += a[i];
		mp[pre] = i+1;
	}
	int ans = 0;
	int suf = 0, cnt = 0;
	for (int i=n-1; i>=0; i--) {
		suf += a[i];
		cnt++;
		if (mp.count(suf)) {
			if (i>mp[suf]-1) {
				ans = max(ans, cnt+mp[suf]);
			}
		}
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