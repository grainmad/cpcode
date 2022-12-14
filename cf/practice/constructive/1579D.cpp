//15:47 17:04
#include <bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;


void sol() {
	int n, a;
	set<pair<int,int>> st;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a;
		if (a>0) st.insert({a, i});
	}
	std::vector<pair<int,int>> ans;
	while(st.size()>1) {
		auto a = *st.begin();
		auto b = *st.rbegin();
		st.erase(a);
		st.erase(b);
		ans.push_back({a.second, b.second});
		if (--a.first>0) st.insert(a);
		if (--b.first>0) st.insert(b);
	}
	cout << ans.size() << '\n';
	for (auto& i : ans) {
		cout << i.first << " " << i.second << '\n';
	}
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
}