#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

string con[6] = {"abc", "acb", "bac", "bca", "cab", "cba"};
string s;
int p[3][N];

void sol() {
	int n, m;
	cin >> n >> m;
	cin >> s;
	for (char ch:{'a', 'b', 'c'}) {
		for (int i=3; i<6; i++) {
			for (int j=i; j<n+3; j+=3) {
				p[ch-'a'][j] = p[ch-'a'][j-3] + (ch==s[j-3]);
			}
		}
	}
	// for (int i=0; i<3; i++) {
	// 	for (int j=0; j<n+3; j++) {
	// 		cout << j << "=" << p[i][j] << ", ";
	// 	} cout << endl;
	// }
	for (int i=0; i<m; i++) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		int ans = r-l+1;
		for (int o=0; o<6; o++) {
			int cnt = 0;
			for (int j=0; j<min(3, r-l+1); j++) {
				int c = con[o][j]-'a';
				cnt += p[c][r-(r-l-j)%3+3]-p[c][l+j];
			}
			ans = min(ans, r-l+1-cnt);
		}
		cout << ans << "\n";
	}
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