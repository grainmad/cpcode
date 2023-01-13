#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	set<char> st;
	for (char i:s) st.insert(i);
	string p(st.begin(), st.end());
	if (k>n) {
		cout << s;
		for (int i=n; i<k; i++) {
			cout << p[0];
		}
		cout << "\n";
	} else {
		for (int i=k-1; i>=0; i--) {
			int pos = find(p.begin(), p.end(), s[i])-p.begin();
			if (pos+1<p.size()) {
				cout << s.substr(0, i) << p[pos+1];
				for (int j=i+1; j<k; j++) {
					cout << p[0];
				}
				cout << "\n";
				return ;
			}
		}
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