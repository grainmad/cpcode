#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

void sol() {
	map<int,int> mp;
	int n;
	cin >> n;
	for (int i=2; i<=n; i++) {
		int x;
		cin >> x;
		mp[x]++;
	}
	std::vector<int> v(1, 1);
	for (auto& i:mp) {
		v.push_back(i.second);
	}
	sort(v.rbegin(), v.rend());
	int ans = v.size();
	for (int i=0; i<ans; i++) {
		v[i] -= ans-i;
	}
	// for (int i:v) cout << i << " ";
	while (!v.empty() && v.back()<=0) v.pop_back();
	while (!v.empty()) {
		int mx = 0;
		for (int i=0; i<v.size(); i++) {
			if (v[i] == v[0]) mx=i;
			else break;
		}
		v[mx]--;
		for (int i=0; i<v.size(); i++) v[i]--;
		ans++;
		while (!v.empty() && v.back()<=0) v.pop_back();
	}
	cout << ans << endl;
	// int sz = v.size();
	// if (v[0] <= sz) cout << sz << endl;
	// else {
	// 	for (int i=0; i<sz; i++) {
	// 		v[i] -= sz-i;
	// 	}
	// 	// for (int i:v) cout << i << " ";
	// 	while (!v.empty() && v.back()<=0) v.pop_back();
	// 	int ans = sz;
	// 	while (!v.empty()) {
	// 		int mx = 0;
	// 		for (int i=0; i<v.size(); i++) {
	// 			if (v[i] == v[0]) mx=i;
	// 			else break;
	// 		}
	// 		v[mx]--;
	// 		for (int i=0; i<v.size(); i++) v[i]--;
	// 		ans++;
	// 		while (!v.empty() && v.back()<=0) v.pop_back();
	// 	}
	// 	cout << ans << endl;
	// 	// for (int j=0; j<=v[0]; j++) {
	// 	// 	int u=0;
	// 	// 	for (int i=0; i<sz; i++) {
	// 	// 		if (v[i]>j) u += v[i]-j;
	// 	// 	}
	// 	// 	if (j>=u) {
	// 	// 		cout << j + sz << endl;
	// 	// 		break;
	// 	// 	}
	// 	// }
	// }
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