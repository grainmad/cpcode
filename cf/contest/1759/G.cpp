#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998224353
using namespace std;

int a[N];

void sol() {
	int n; cin >> n;
	set<int> st;
	for (int i=1; i<=n; i++) a[i] = 0, st.insert(i);
	for (int i=1; i<=n/2; i++) {
		cin >> a[i*2];
		st.erase(a[i*2]);
	}
	if (st.size() != n/2) {
		cout << "-1\n";
		return ;
	}
	int ok = 1;
	for (int i=n; i>=2; i-=2) {
		auto it = st.upper_bound(a[i]);
		if (it == st.begin()) {
			ok = 0;
			break;
		}
		--it;
		a[i-1] = *it;
		st.erase(it);
	}
	if (ok) {
		for (int i=1; i<=n; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
	} else {
		cout << "-1\n";
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