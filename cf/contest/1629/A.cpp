#include <bits/stdc++.h>
using namespace std;

struct Node {
	int a, b;
	bool operator<(const Node& o) const {
		return a < o.a;
	}
} m[105];

void sol() {
	int n, k;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> m[i].a;
	}
	for (int i=0; i<n; i++) {
		cin >> m[i].b;
	}
	sort(m, m+n);
	for (int i=0; i<n; i++) {
		if (k>=m[i].a) k += m[i].b;
		else break;
	}
	cout << k << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
