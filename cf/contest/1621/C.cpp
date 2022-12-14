#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;


void sol() {
	int n;
	cin >> n;
	std::vector<int> v(n+1, 0);
	for (int i = 1; i <= n; ++i) {
		if (v[i] != 0) continue;
		int ed, u, p;
		cout << "? " << i << endl;
		cin >> ed;
		p = ed;
		while (1) {
			cout << "? " << i << endl;
			cin >> u;
			v[p] = u;
			if (u == ed) break;
			p = u;
		}
	}
	cout << "! ";
	for (int i=1; i<v.size(); i++) cout << v[i] << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
	cout.flush();
	return 0;
}