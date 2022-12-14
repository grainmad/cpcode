#include <bits/stdc++.h>
#define ll long long
#define BIAS 200005
#define MAXN 400005
using namespace std;


vector<pair<int,int>> mp[MAXN];
string s[MAXN];
int pos[MAXN];


void dfs(int u) {
	// cout << u << endl;
	while (pos[u] < mp[u].size()) {
		int v = mp[u][pos[u]].first, idx = mp[u][pos[u]].second;
		if (v == -1) {
			pos[u]++;
			continue;
		}
		mp[v][idx].first = -1;
		mp[u][pos[u]].first = -1;
		if (u < BIAS) s[u][pos[u]] = 'R';
		pos[u]++;
		dfs(v);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m; cin >> m;
	unordered_map<int,int> cnt, idx;

	int p=0;

	for (int i=0; i<m; i++) {
		int n, u;
		cin >> n;
		s[i].resize(n, 'L');
		for (int j=0; j<n; j++) {
			cin >> u;
			cnt[u]++;
			if (idx.count(u) == 0) idx[u] = p++;
			u = idx[u];
			mp[i].push_back({u+BIAS, mp[u+BIAS].size()});
			mp[u+BIAS].push_back({i, mp[i].size()-1});
		}
	}
	
	//出现次数为奇数
	for (auto& i : cnt) {
		int c = i.second;
		if (c%2 == 1) {
			cout << "NO\n";
			return 0;
		}
	}

	for (int i=0; i<m; i++) {
		dfs(i);
	}
	cout << "YES\n";
	for (int i=0; i<m; i++) {
		cout << s[i] << '\n';
	}
	return 0;
}