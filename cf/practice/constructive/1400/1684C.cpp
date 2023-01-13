#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m, 0));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> g[i][j];
		}
	}
	vector<int> vis(m, 0);
	for (auto& r:g) {
		int a=-1, b=-1;
		for (int i=1; i<r.size(); i++) {
			if (r[i-1] > r[i]) {
				a = i-1;
				while (a>0 && r[a]==r[a-1]) a--;
				break;
			}
		}
		for (int i=r.size()-1; i>=1; i--) {
			if (r[i-1] > r[i]) {
				b = i;
				while (b+1<r.size() && r[b] == r[b+1]) b++;
				break;
			}
		}
		
		if (a != b) {
			swap(r[a], r[b]);
			if (!is_sorted(r.begin(), r.end())) {
				cout << "-1" << endl;
				return;
			}
			swap(r[a], r[b]);
			vis[a]++; vis[b]++;
		}
	}
	std::vector<int> v;
	for (int i=0; i<vis.size(); i++) {
		if (vis[i]) v.push_back(i);
	}
	if (2 == v.size()) {
		for (int i=0; i<n; i++) {
			if (g[i][v[0]] < g[i][v[1]]) {
				cout << "-1" << endl;
				return ;
			}
		}
		cout << v[0]+1 << " " << v[1]+1 << endl;
	} else if (v.size() > 2) {
		cout << "-1" << endl;
	} else cout << "1 1" << endl;
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