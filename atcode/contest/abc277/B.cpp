#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998224353
using namespace std;


void sol() {
	int n;
	cin >> n;
	bool ok = 1;
	set<string> st;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		if (st.count(s)) ok = 0;
		st.insert(s);
		if ("HDCS"s.find(s[0]) == string::npos) ok = 0;
		if ("A23456789TJQK"s.find(s[1]) == string::npos) ok = 0;
	}
	cout << (ok?"Yes":"No") << endl;
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