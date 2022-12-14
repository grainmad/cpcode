//C
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
bool st[55];


void sol() {
	memset(st, false, sizeof(st));
	bool ips = false;
	cin >> n;
	int t;
	for (int i=1; i<=n; i++) { 
		cin >> t;
		while (t>n) t/=2;
		while (t>0 && st[t]) {
			t/=2;
		}
		if (t == 0) ips = true;
		else st[t] = true;
	}
	for (int i=1; i<=n; i++) {
		if (!st[i]) {
			ips = true;
			break;
		}
	}
	cout << (ips?"NO":"YES") << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
	return 0;
}
