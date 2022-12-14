#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define INF 0x3f3f3f3f
#define N 500005
using namespace std;

// 当前i，alice已选j，奇数剩余k，偶数剩余l
int dp[2][2][100][100];

int dfs(int turn, int sl, int a, int b) {
	if (dp[turn][sl][a][b] != INF) return dp[turn][sl][a][b];
	if (turn%2) {
		if (b == 0) return dp[turn][sl][a][b] = (a/2+sl)%2?1:-1;
		if (a == 0) return dp[turn][sl][a][b] = sl?1:-1;
		if (a>0 && dfs(1-turn, sl, a-1, b)==-1) return dp[turn][sl][a][b] = 1;
		if (b>0 && dfs(1-turn, sl, a, b-1)==-1) return dp[turn][sl][a][b] = 1;
		return dp[turn][sl][a][b] = -1;
	} else {
		if (b == 0) return dp[turn][sl][a][b] = ((a+1)/2+sl)%2?-1:1;
		if (a == 0) return dp[turn][sl][a][b] = sl?-1:1;
		if (a>0 && dfs(1-turn, (sl+1)%2, a-1, b)==-1) return dp[turn][sl][a][b] = 1;
		if (b>0 && dfs(1-turn, sl, a, b-1)==-1) return dp[turn][sl][a][b] = 1;
		return dp[turn][sl][a][b] = -1;
	}
}

void sol() {
	int n;
	cin >> n;
	int o=0, e=0, x;
	for (int i=0; i<n; i++) {
		cin >> x;
		if (x%2) o++;
		else e++;
	}
	memset(dp, 0x3f, sizeof(dp));
	cout << (dfs(0, 0, o, e) == 1?"Alice":"Bob") << "\n";
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