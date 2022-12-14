#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	set<int> st;
	for (int i=n-1; i>=0; i--) {
		st.insert(a[i]);
		if (st.size() != n-i) {
			cout << i+1<< endl;
			return;
		}
	}
	cout << 0 << endl;
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