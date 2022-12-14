#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N], b[N], c[N];

void sol() {
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++) cin >> b[i];
	for (int i=1; i<=m; i++) cin >> c[i];
	int dif = 0;
	vector<vector<int>> mp(n+1);
	for (int i=1; i<=n; i++) {
		if (a[i] != b[i]) {
			dif++;
			mp[b[i]].push_back(i);
		} 
	}
	// cout << n << " " << m << " " << dif << endl;
	if (dif) {
		int ok = 0;
		for (int i=1; i<=n; i++) {
			if (b[i] == c[m]) ok = 1;
		}
		if (!ok) {
			cout << "NO\n";
			return ;
		}
		std::vector<int> v(m+1);
		for (int i=m; i>0; i--) {
			if (mp[c[i]].size()) {
				dif--;
				v[i] = mp[c[i]].back();
				mp[c[i]].pop_back();
			} else {
				if (i != m) {
					v[i] = v[i+1];	
				} else {
					for (int i=1; i<=n; i++) {
						if (b[i] == c[m]) {
							v[m] = i;
							break;
						}
					}
				}
				
			}
		}
		if (dif) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for (int i=1; i<=m; i++) {
				cout << v[i] << " ";
			}
			cout << "\n";	
		}
	} else {
		int pos = -1;
		for (int i=1; i<=n; i++) {
			if (a[i] == c[m]) pos = i;
		}
		if (pos != -1) {
			cout << "YES\n";
			for (int i=1; i<=m; i++) {
				cout << pos << " ";
			}
			cout << endl;
		} else {
			cout << "NO\n";
		}
	}
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