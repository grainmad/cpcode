#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1" << endl;
		return;
	}
	int x, y;
	vector<vector<ll> > v(n, vector<ll> (n, 0));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> v[i][j];
			if (v[i][j] == 0) x = i, y = j;
		}
	}
	v[x][y] = accumulate(v[(x+1)%n].begin(), v[(x+1)%n].end(), 0LL) - accumulate(v[x].begin(), v[x].end(), 0LL);
	if (v[x][y] <= 0) {
		cout << "-1" << endl;
		return ;
	}
	ll sum = accumulate(v[0].begin(), v[0].end(), 0LL);
	ll cnt = 0;
	for (int i=0; i<n; i++) {
		cnt += v[i][i];
	}
	if (cnt != sum) {
		cout << "-1" << endl;
		return ;
	}
	cnt = 0;
	for (int i=0; i<n; i++) {
		cnt += v[i][n-i-1];
	}
	if (cnt != sum) {
		cout << "-1" << endl;
		return ;
	}
	for (int i=0; i<n; i++) {
		if (accumulate(v[i].begin(), v[i].end(), 0LL) != sum) {
			cout << "-1" << endl;
			return ;
		}
		cnt = 0;
		for (int j=0; j<n; j++) {
			cnt += v[j][i];
		}
		if (cnt != sum) {
			cout << "-1" << endl;
			return ;
		}
	}
	cout << v[x][y] << endl;
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