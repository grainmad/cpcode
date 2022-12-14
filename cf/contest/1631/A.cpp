#include <bits/stdc++.h>
#define MAXN 205

using namespace std;

int n1[MAXN], n2[MAXN];

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> n1[i];
	}
	for (int i=0; i<n; i++) {
		cin >> n2[i];
	}
	int a = 0, b = 0;
	for (int i=0; i<n; i++) {
		if (n1[i]>n2[i]) swap(n1[i], n2[i]);
		a = max(n1[i], a);
		b = max(n2[i], b);
	}
	cout << a*b << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		sol();
	}
	return 0;
}