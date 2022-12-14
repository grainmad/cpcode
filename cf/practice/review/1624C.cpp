#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;


void sol() {
	int n;
	cin >> n;
	std::vector<bool> v(n+1);
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		while (x) {
			if (x<=n && !v[x]) {
				v[x] = true;
				break;
			}
			x/=2;
		}
	}
	bool ok = true;
	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			ok = false;
			break;
		}
	}
	cout << (ok?"YES":"NO") << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}