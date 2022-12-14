#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
string g[4] = {"123","456","789"," 0 "};


pair<int,int> pos(char a) {
	for (int i=0; i<4; i++) {
		for (int j=0; j<3; j++) {
			if (g[i][j] == a) return {i, j};
		} 
	}
}
bool ok(pair<int,int>& p) {
	if (p.first<0 || p.first>=4 || p.second<0 || p.second>=3) return false;
	if (p.first == 3 && (p.second == 0 || p.second == 2)) return false;
	return true;
}

void sol() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i=0; i<4; i++) {
		bool no = 1;
		for (char j:s) {
			auto p = pos(j);
			p.first += dir[i][0];
			p.second += dir[i][1];
			// cout << p.first << " " << p.second << " " << ok(p) << endl;
			if (!ok(p)) {
				no = 0;
				break;
			}
		}
		if (no) {
			cout << "NO" << endl;
			return ;
		}
	}
	cout << "YES" << endl;
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