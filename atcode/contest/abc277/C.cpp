#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998224353
using namespace std;


void sol() {
	int n;
	cin >> n;
	unordered_map<int, vector<int>> mp;
	set<int> st;
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	queue<int> que;
	que.push(1);
	st.insert(1);
	while (que.size()) {
		int u = que.front(); que.pop();
		for (int i:mp[u]) {
			if (st.count(i)) continue;
			st.insert(i);
			que.push(i);
		}
	}
	cout << *st.rbegin() << endl;
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