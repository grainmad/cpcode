#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int e[200];
char d[3] = {'R', 'G', 'B'};
void sol() {
	e['R'] = 0; e['G'] = 1; e['B'] = 2;
	int n; cin >> n;
	string s; cin >> s;
	int cnt = 0;
	for (int i=1; i<n; i++) {
		if (s[i] != s[i-1]) continue;
		if (i == n-1 || e[s[i-1]] == e[s[i+1]]) {
			s[i] = d[(e[s[i-1]]+1)%3];
		} else {
			s[i] = d[3-e[s[i-1]]-e[s[i+1]]];
		}
		cnt++;
	}
	cout << cnt << endl;
	cout << s << endl;
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