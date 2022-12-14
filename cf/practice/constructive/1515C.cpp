#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, m, x;
	cin >> n >> m >> x;
	std::vector<int> v;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
	for (int i=1; i<=m; i++) que.emplace(0, i);
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		auto u = que.top();
		v.push_back(u.second);
		que.pop();
		u.first += x;
		que.push(u);
	}
	cout << "YES" << endl;
	for (int i:v) cout << i << " ";
	cout << endl;
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