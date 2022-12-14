#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	std::map<int, int> mp;
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		mp[x]++;
	}
	int cnt1 = 0, cnt2=0;
	for (auto i:mp) {
		if (i.second == 1) cnt1++;
		else cnt2++;
	}
	cout << (cnt2+(cnt1+1)/2) << endl;
	
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
