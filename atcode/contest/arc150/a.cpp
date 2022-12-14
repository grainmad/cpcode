#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> p0(n+1, 0), p1(n+1, 0);
	for (int i=1; i<=n; i++) {
		p1[i] = p1[i-1]+(s[i-1]=='1');
		p0[i] = p0[i-1]+(s[i-1]=='0');
	}
	int ans = 0;
	for (int i=k; i<=n; i++) {
		if (p0[i]-p0[i-k] == 0 && p1[i-k] == 0 && p1[n]-p1[i] == 0) {
			ans++;
		}
	}
	cout << (ans==1?"Yes\n":"No\n");
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