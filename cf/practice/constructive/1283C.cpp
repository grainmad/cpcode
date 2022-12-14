#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

int a[N], h[N];

void sol() {
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		h[a[i]] = 1;
	}
	std::vector<int> v;
	for (int i=1; i<=n; i++) {
		if (a[i] == 0 && h[i] == 0) v.push_back(i);
	}
	for (int i=1; i<=n; i++) {
		if (a[i] != 0 && h[i] == 0) v.push_back(i);
	}
	// for (int i:v) cout << i << " "; cout << endl;
	int p=0, sz = v.size();
	for (int i=1; i<=n; i++) {
		if (a[i] == 0 && h[i] == 0) a[i] = v[(++p)%sz];
	}
	for (int i=1; i<=n; i++) {
		if (a[i] == 0 && h[i] != 0) a[i] = v[(++p)%sz];
	}
	for (int i=1; i<=n; i++) {
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