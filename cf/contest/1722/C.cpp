#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	set<string> st[3];
	map<string,int> mp;
	int n;
	cin >> n;
	for (int j=0; j<3; j++)
	for (int i=0; i<n; i++) {
		string s; cin >> s;
		st[j].insert(s);
	}
	for (int i=0; i<3; i++)
	for (auto& j:st[i]) mp[j]++;

	int a[3] = {0};
	for (int i=0; i<3; i++)
	for (auto& j:st[i]) {
		if (mp[j] == 1) a[i] += 3;
		if (mp[j] == 2) a[i] += 1;
	}	
	for (int i=0; i<3; i++) {
		cout << a[i] << " ";
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