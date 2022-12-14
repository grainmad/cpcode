#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int d[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};

void sol() {
	string s; int x, y;
	cin >> s;
	x = y = 0;
	set<pair<int,int>> st;
	st.insert({x, y});
	for (char i:s) {
		if (i == 'L') x--;
		if (i == 'R') x++;
		if (i == 'U') y--;
		if (i == 'D') y++;
		int cnt = 0;
		for (int i=0; i<4; i++) {
			int mx = x+d[i][0], my = y+d[i][1];
			if (st.count({mx, my})) {
				cnt++;
			}
		}
		if (st.count({x,y}) || cnt > 1) {
			cout << "BUG\n";
			return ;
		}
		st.insert({x, y});
	}
	cout << "OK\n";
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