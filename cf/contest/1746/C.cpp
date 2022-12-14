#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];

void sol() {
	int n;
	cin >> n;
	std::vector<vector<int>> v(n+1);
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	int inv = 0;
	for (int i=2; i<=n; i++) {
		if (a[i-1]>a[i]) {
			v[a[i-1]-a[i]].push_back(i);
			inv++;
		}
	}
	for (int i=0; i<n-inv; i++) {
		cout << "1 ";
	}
	for (auto& i:v) {
		for (int j:i) {
			cout << j << " ";
		}
	}
	cout << "\n";
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