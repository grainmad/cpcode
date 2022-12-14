#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
using namespace std;


void sol() {
	string s; cin >> s;
	cout << 3 << endl;
	cout << "R " << s.size()-1 << endl;
	cout << "L " << s.size() << endl;
	cout << "L " << 2 << endl;
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