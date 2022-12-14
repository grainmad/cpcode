#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	string s;
	cin >> s;
	for (int i=0; i<s.size(); i++) {
		if (s[i] == '-') continue;
		s[i] = (s[i]-'0'+1)%10+'0';
	}
	cout << s << endl;
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