#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 9
using namespace std;

string s[9];
bool ok(int x, int y) {
	if (x<0 || x>=9 || y<0 || y>=9) return false;
	return s[x][y] == '#';
}

void sol() {
	for (int i=0; i<N; i++) cin >> s[i];
	int ans = 0;
	for (int a=1; a<9; a++) {
		for (int b=0; b<9; b++) {
			for (int i=0; i<9; i++) {
				for (int j=0; j<9; j++) {
					if (ok(i,j) && ok(i+a, j+b) && ok(i+a-b, j+a+b) && ok(i-b, j+a)) {
						ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
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