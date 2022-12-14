#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	string s, t;
	cin >> s >> t;
	bool flag = false;
	for (char i:t) {
		if (i == 'a') flag=true;
	}
	if (flag && t.size()>1) {
		cout << -1 << endl;
	} else {
		if (t.size() == 1 && flag) cout << 1 << endl;
		else cout << (1LL<<s.size()) << endl;
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