#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;
int n; 
string s, ans;

bool dfs(int p) {
	if (p == n) return true;
	if (p+2<n && s[p+2] == '0' && 10<=(s[p]-'0')*10+s[p+1]-'0' && (s[p]-'0')*10+s[p+1]-'0'<=26) {
		ans.push_back((s[p]-'0')*10+s[p+1]-'0'+'a'-1);
		if (dfs(p+3)) return true;
		ans.pop_back();
	}
	if (s[p]-'0' > 0) {
		ans.push_back(s[p]-'0'+'a'-1);
		if (dfs(p+1)) return true;
		ans.pop_back();
	}
	return false;
}

void sol() {
	cin >> n;
	cin >> s;
	ans = "";
	dfs(0);
	cout << ans << "\n";
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