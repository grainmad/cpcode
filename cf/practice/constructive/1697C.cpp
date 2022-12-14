//14:23 
#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n; string t, s;
	cin >> n >> t >> s;
	if (count(t.begin(), t.end(), 'b') != count(s.begin(), s.end(), 'b')) {
		cout << "NO" << endl;
		return;
	}
	string a, b;
	for (char i:t) if (i != 'b') a.push_back(i);
	for (char i:s) if (i != 'b') b.push_back(i);
	if (a != b) {
		cout << "NO" << endl;
		return ;
	}
	std::vector<int> idx;
	for (int i=0; i<n; i++) {
		if (t[i] != 'b') idx.push_back(i);
	}
	for (int i=0, p=0; i<n; i++) {
		if (s[i] != 'b') {
			if (s[i] == 'a' && idx[p]>i || s[i] == 'c' && idx[p]<i) {
				cout << "NO" << endl;
				return ;
			} 
			p++;
		}
	}
	cout << "YES" << endl;
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