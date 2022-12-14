#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 105
using namespace std;

string s[N];
int p[N];

void sol() {
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> s[i];
	}
	
	int ans = 0;
	for (int i=0; i<m; i++) {
		int ok = 1;
		for (int j=1; j<n; j++) {
			if (!p[j] && s[j-1][i]>s[j][i]) {
				ok = 0;
			}
		}
		if (ok) {
			for (int j=1; j<n; j++) {
				if (s[j-1][i] < s[j][i]) p[j] = 1;
			}
		} else ans++;
	}
	cout << ans << "\n";
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