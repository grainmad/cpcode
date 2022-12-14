#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	string s;
	cin >> s;
	int n = s.size();
	vector<pair<char,int>> v;
	for (int i=0; i<n; i++) {
		v.push_back({s[i], i});
	}
	vector<int> ans;
	if (s[0] >= s[n-1]) {
		sort(v.begin()+1, v.end()-1, [](auto& a, auto& b) {
			return a.first > b.first;
		});
		for (int i=0; i<n; i++) {
			if (s[0]>=v[i].first && v[i].first>=s[n-1]) {
				ans.push_back(v[i].second);
			}
		}
	} else {
		sort(v.begin()+1, v.end()-1);
		for (int i=0; i<n; i++) {
			if (s[0]<=v[i].first && v[i].first<=s[n-1]) {
				ans.push_back(v[i].second);
			}
		}
	}
	int dif = 0;
	for (int i=1; i<ans.size(); i++) {
		dif += abs(s[ans[i]]-s[ans[i-1]]);
	}
	cout << dif << " " << ans.size() << "\n";
	for (int i:ans) cout << i+1 << " ";
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