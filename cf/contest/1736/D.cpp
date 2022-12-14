#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (count(s.begin(), s.end(), '1')%2 || count(s.begin(), s.end(), '0')%2) {
		cout << "-1\n";
		return ;
	}
	std::vector<int> b;
	for (int i=0, j=1; i<2*n; i+=2) {
		if (s[i] != s[i+1]) {
			// if (j) {
			// 	b.push_back(s[i]=='1'?i:i+1);
			// } else {
			// 	b.push_back(s[i]=='0'?i:i+1);
			// }
			if (s[i] == '1' && j || s[i] == '0' && !j) b.push_back(i);
			else b.push_back(i+1);
			j = 1-j;
		}
	}
	cout << b.size();
	for (int i:b) cout << " " << i+1;
	cout << "\n";
	for (int i=1; i<=2*n; i+=2) {
		cout << i << " ";
	}
	cout << "\n";
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