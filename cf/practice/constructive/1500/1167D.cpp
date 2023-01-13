#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> p(n);
	for (int i=0; i<n; i++) {
		if (s[i] == ')') {
			if (s[i-1] == '(') p[i] = i-1;
			else {
				int u = i-1;
				while (s[u] == ')') {
					u = p[u]-1;
				}
				p[i] = u;
			}
		}
		// cout << p[i] << " ";
	}
	string ans(n, '0');
	int deep = 0;
	for (int i=n-1; i>=0; i--) {
		if (s[i] == '(') deep--;
		else {
			deep++;
			ans[i] = ans[p[i]] = (deep%2?'1':'0');
		}
		
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