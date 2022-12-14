#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;


void sol() {
	map<int,int> mp;
	int n, t;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> t;
		mp[t]++;
	}
	std::vector<int> v, ans;
	for (auto& i : mp) {
		v.push_back(i.second);
	}
	int cnt = v.size();
	for (int i=1; i<=n; i++) {
		ans.push_back((i<=cnt?cnt:i));
	}
	cout << ans[0];
	for (int i=1; i<ans.size(); i++) {
		cout << " " << ans[i];
	}
	cout << '\n';
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