#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	string s;
	cin >> s;
	set<char> st;
	int day = 1;
	for (int i=0; i<s.size(); i++) {
		if (st.count(s[i])) continue;
		if (st.size() == 3) {
			st.clear();
			day++;
		}
		st.insert(s[i]);
	}
	cout << day << endl;
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