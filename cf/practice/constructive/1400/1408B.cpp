#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	set<int> st;
	int n, k;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		st.insert(x);
	}
	int sz = st.size();
	if (k == 1) {
		cout << (sz==1?1:-1) << endl;
	} else cout << max(1, (sz+k-3)/(k-1)) << endl;
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