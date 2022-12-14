#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int num[10004];

void sol() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> num[i];
	}
	bool flag = true;
	int mx = num[0];
	for (int i=1; i<n; i++) {
		if (num[i] < mx) {
			flag = false;
			break;
		}
		mx = max(mx, num[i]);
	}
	cout << (flag?"NO":"YES") << '\n';
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