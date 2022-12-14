#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];

void sol() {
	int n;
	cin >> n;
	vector<int> v(n+1, 0);
	for (int i=0; i<n; i++) {
		cin >> a[i];
		v[a[i]] = 1;
	}
	set<int> st;
	for (int i=1; i<=n; i++) {
		if (!v[i]) st.insert(i);
	}
	auto t = st;
	for (int i=0; i<n; i++) {
		if (i==0 || a[i-1] != a[i]) cout << a[i] << " ";
		else {
			cout << *t.begin() << " ";
			t.erase(t.begin());
		}
	}
	cout << "\n";
	t = st;
	for (int i=0; i<n; i++) {
		if (i==0 || a[i-1] != a[i]) cout << a[i] << " ";
		else {
			auto it = --t.upper_bound(a[i]);
			cout << *it << " ";
			t.erase(it);
		}
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