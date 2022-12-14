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
	if (k<st.size()) cout << "-1" << endl;
	else {
		cout << k*n << endl;
		for (int i=0; i<n; i++) {
			for (int j:st) {
				cout << j << " ";
			}
			for (int j=st.size(); j<k; j++) {
				cout << "1 ";
			}
		}
		cout << endl;
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