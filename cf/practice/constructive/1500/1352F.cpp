#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n0, n1, n2;
	cin >> n0 >> n1 >> n2;
	string s;
	for (int i=0; i<n0; i++) {
		if (s.empty()) s += "00";
		else s.push_back('0');
	}
	if (n1 > 0) {
		if (s.empty()) s+="01";
		else s.push_back('1');
		n1--;
	}
	for (int i=0; i<n2; i++) {
		if (s.empty()) s+="11";
		else s.push_back('1');
	}
	for (int i=0; i<n1; i++) {
		s.push_back(s.back()=='0'?'1':'0');
	}
	cout << s << "\n";
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