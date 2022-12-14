//E
#include <bits/stdc++.h>
using namespace std;

struct Seg {
	int l, r, i;
};
unordered_map<string, Seg> mp;
int n, m;
string s[1005];
string dp[1005];
int fa[1005];
/*
4 3
193
391
301
359
035
*/

void sol() {
	mp.clear();
	for (int i=0; i<1005; i++) dp[i] = "";
	memset(fa, 0, sizeof(fa));
	cin >> n >> m; 
	for (int i=1; i<=n; i++) {
		cin >> s[i];
	}
	cin >> s[0];
	if (m < 2) {
		cout << -1 << endl;
		return;
	}
	for (int i=1; i<=n; i++) {
		
		for (int j=0; j<m-1; j++) {
			string t = s[i].substr(j, 2);
			mp[t].l = j+1;
			mp[t].r = j+2;
			mp[t].i = i;
		}
		
		for (int j=0; j<m-2; j++) {
			string t = s[i].substr(j, 3);
			mp[t].l = j+1;
			mp[t].r = j+3;
			mp[t].i = i;
		}
	}
	if (mp.count(s[0].substr(0, 2)) == 1) dp[1] = s[0].substr(0, 2);
	if (m>2 && mp.count(s[0].substr(0, 3)) == 1) dp[2] = s[0].substr(0, 3);
	for (int i=3; i<m; i++) {
		if (dp[i-3] != "" && mp[s[0].substr(i-2, 3)].i != 0) {
			dp[i] = s[0].substr(i-2, 3);
			fa[i] = i-3;
		}
		if (dp[i-2] != "" && mp[s[0].substr(i-1, 2)].i != 0) {
			dp[i] = s[0].substr(i-1, 2);
			fa[i] = i-2;
		}
		
	}
//	for (int i=0; i<m; i++) {
//		cout << dp[i] << " ";
//	} cout << endl;
	if (dp[m-1] == "") cout << -1 << endl;
	else {
		vector<string> ha;
		int t = m-1;
		while (t != 0) {
			ha.push_back(dp[t]);
			t = fa[t];
		}
//		for (int i:ha) {
//			cout << i << endl;
//		}cout << endl;
		reverse(ha.begin(), ha.end());
		cout << ha.size() << endl;
		for (auto &i : ha) {
			cout << mp[i].l << " " << mp[i].r << " " << mp[i].i << endl;
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}	
	return 0;
}
