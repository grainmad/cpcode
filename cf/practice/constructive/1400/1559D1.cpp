#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 1005
using namespace std;

int st[2][N];
int ufind(int id, int x) {
	if (st[id][x] == x) return x;
	return st[id][x] = ufind(id, st[id][x]);
}

void sol() {
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	for (int i=1; i<=n; i++) {
		st[0][i] = st[1][i] = i;
	}
	for (int i=0; i<m1; i++) {
		int x, y; cin >> x >> y;
		st[0][ufind(0, x)] = ufind(0, y);
	}
	for (int i=0; i<m2; i++) {
		int x, y; cin >> x >> y;
		st[1][ufind(1, x)] = ufind(1, y);
	}
	std::vector<pair<int,int>> v;
	for (int i=1; i<=n; i++) {
		for (int j=i+1; j<=n; j++) {
			int fi0 = ufind(0, i), fj0 = ufind(0, j);
			int fi1 = ufind(1, i), fj1 = ufind(1, j);
			if (fi0 != fj0 && fi1 != fj1) {
				v.emplace_back(i, j);
				st[0][fi0] = fj0;
				st[1][fi1] = fj1;
			}
		}
	}
	cout << v.size() << endl;
	for (auto i:v) {
		cout << i.first << " " << i.second << endl;
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