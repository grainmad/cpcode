#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
	string s;
	int h, w, cnt = 0;
	cin >> h >> w;
	for (int i=0; i<h; i++) {
		cin >> s;
		for (int j=0; j<w; j++) {
			cnt += s[j] == '#';
		}
	}
	cout << cnt << endl;

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