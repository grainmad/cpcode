#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	string s; int n;
	cin >> s >> n;
	std::map<char, int> mp;
	std::vector<int> v(26, 0);
	for (char i:s) {
		mp[i]++;
		v[i-'a'] = 1;
	}
	if (mp.size() > n) {
		cout << "-1\n";
		return;
	}
	for (int i=0,sz=n-mp.size(); i<sz; i++) {
		int mx = 0, idx;
		for (int j=0; j<26; j++) {
			if (v[j] > 0 && (mp['a'+j]+v[j]-1)/v[j] > mx) {
				mx = (mp['a'+j]+v[j]-1)/v[j];
				idx = j;
			}
		}
		v[idx]++;
	}
	int ans = 0;
	string ss;
	for (int i=0; i<26; i++) {
		if (v[i] > 0) {
			ss += string(v[i], 'a'+i);
			if ((mp['a'+i]+v[i]-1)/v[i]>ans) ans = (mp['a'+i]+v[i]-1)/v[i];
		}
	}
	cout << ans << "\n" << ss << "\n";
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