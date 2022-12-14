#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 1005
using namespace std;

string s[N];

void sol() {
	int n, ans = 6;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> s[i];
		for (int j=i-1; j>=0; j--) {
			int dif = 0;
			for (int k=0; k<6; k++) {
				if (s[i][k] != s[j][k]) dif++;
			}
			ans = min(ans, (dif-1)/2);
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