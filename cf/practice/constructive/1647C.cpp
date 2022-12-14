//16：01 16:29
#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 105
using namespace std;

string g[N];

void sol() {
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> g[i];
	}
	if (g[0][0] == '1') {
		cout << "-1\n";
		return ;
	}
	std::vector<vector<int>> v;
	for (int i=0; i<n; i++) {
		for (int j=m-2; j>=0; j--) {
			if (g[i][j+1] == '1') {
				v.push_back({i, j, i, j+1});
				// cout << i << " " << j << " " << i << " " << j+1 << '\n';
			}
		}	
	}
	for (int i=n-2; i>=0; i--) {
		if (g[i+1][0] == '1') {
			v.push_back({i, 0, i+1, 0});
			// cout << i << " 0 " << i+1 << " 0\n";
		}
	}
	cout << v.size() << endl;
	for (auto& i:v) {
		for (int j:i) {
			cout << j+1 << " ";
		} 
		cout << '\n';
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