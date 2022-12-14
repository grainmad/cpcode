#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 3000005
using namespace std;

void sol() {
	int n; cin >> n;
	string s; cin >> s;
	string ans = s;
	int k = 1;
	for (int i=1; i<n; i++) {
		string u = s.substr(i), v = s.substr(0, i);
		if ((n-i)%2) {
			reverse(v.begin(), v.end());
		}
		string t = u+v;
		if (t<ans) {
			ans = t;
			k = i+1;
		}
	}
	cout << ans << "\n" << k << endl;
}

int main() {
	// for (int i=0; i<2500; i++) cout << "ab";
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