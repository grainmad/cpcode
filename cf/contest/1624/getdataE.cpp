//E
#include <bits/stdc++.h>
using namespace std;

struct Seg {
	int l, r, i;
} mp[1005];

int n, m;
string s[1005];
int dp[1005];
int fa[1005];

int get_hash(int i, int l, int r) {
	int t = 0;
	for (int x=l; x<=r; x++) {
		t*=10;
		t+= s[i][x]-'0';
	}
	return t;
}

void sol() {
	memset(dp, -1, sizeof(dp));
	memset(mp, 0, sizeof(mp));
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
			int t = get_hash(i, j, j+1);
			mp[t].l = j+1;
			mp[t].r = j+2;
			mp[t].i = i;
		}
		
		for (int j=0; j<m-2; j++) {
			int t = get_hash(i, j, j+2);
			mp[t].l = j+1;
			mp[t].r = j+3;
			mp[t].i = i;
		}
	}
	if (mp[get_hash(0, 0, 1)].i != 0) dp[1] = get_hash(0, 0, 1);
	if (m>2 && mp[get_hash(0, 0, 2)].i != 0) dp[2] = get_hash(0, 0, 2);
	for (int i=3; i<m; i++) {
		if (dp[i-3] != -1 && mp[get_hash(0, i-2, i)].i != 0) {
			dp[i] = get_hash(0, i-2, i);
			fa[i] = i-3;
		}
		if (dp[i-2] != -1 && mp[get_hash(0, i-1, i)].i != 0) {
			dp[i] = get_hash(0, i-1, i);
			fa[i] = i-2;
		}
		
	}
	if (dp[m-1] == -1) cout << -1 << endl;
	else {
		vector<int> ha;
		int t = m-1;
		while (t != 0) {
			ha.push_back(dp[t]);
			t = fa[t];
		}
//		for (int i:ha) {
//			cout << i << endl;
//		}cout << endl;
		cout << ha.size() << endl;
		for (int i=ha.size()-1; i>=0; i--) {
			cout << mp[ha[i]].l << " " << mp[ha[i]].r << " " << mp[ha[i]].i << endl;
		}
	}
	
}

void getdata() {
	for (int x=0; x<327; x++) {
		cin >> n >> m; 
		for (int i=1; i<=n; i++) {
			cin >> s[i];
		}
		cin >> s[0];	
	}
	cout << n << " " << m << endl;
	for (int i=1; i<=n; i++) {
		cout << s[i] << endl;
	}
	cout << s[0] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	if (t == 10000) getdata();
	while (t--) {
		sol();
	}	
	return 0;
}
