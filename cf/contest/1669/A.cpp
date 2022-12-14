#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int r;
	cin >> r;
	if (r >= 1900) cout << "Division 1" << endl;
	else if (1600 <= r && r < 1900) cout << "Division 2" << endl;
	else if (1400 <= r && r < 1600) cout << "Division 3" << endl;
	else cout << "Division 4" << endl;
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