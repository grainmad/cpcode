#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, k;
	string s;
	cin >> n;
	cin >> s;
	cin >> k;
	std::vector<int> vis(26, false);
	for (int i=0; i<k; i++) {
		string t;
		cin >> t;
		vis[t[0]-'a'] = true;
	}
	int pos = -1;
	for (int i=0; i<n; i++) {
		if (vis[s[i]-'a']) pos = i;
	}
	// for (auto i:vis) {
	// 	cout << i << " ";
	// } cout << endl;
	queue<char> que;
	for (int i=0; i<=pos; i++) {
		que.emplace(s[i]);
	}
	int ans = 0;
	while (que.size() > 1) {
		ans ++;
		int sz = que.size();
		for (int i=0; i<sz-1; i++) {
			char u = que.front(); que.pop();
			if (!vis[que.front()-'a']) que.emplace(u);
		}
		que.emplace(que.front()); que.pop();
		// auto temp = que;
		// while (!temp.empty()) {
		// 	cout << temp.front();
		// 	temp.pop();
		// } cout << endl;
	}
	cout << ans << endl;
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