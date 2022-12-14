#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int name = 0;

string getname() {
	string rt(2, 'A');
	rt[0] = name/26+'A';
	rt[1] = name%26+'a';
	name++;
	return rt;
}


void sol() {
	int n, k;
	cin >> n >> k;
	std::vector<string> v(n-k+1);
	for (int i=0; i<n-k+1; i++) {
		cin >> v[i];
	}
	std::vector<string> ans;
	for (int i=0; i<k-1; i++) {
		ans.push_back(getname());
	}
	for (int i=0; i<n-k+1; i++) {
		if (v[i] == "YES") ans.push_back(getname());
		else ans.push_back(ans[ans.size()+1-k]);
	}
	for (auto& i:ans) cout << i << " ";
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