#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int num[505];

void sol() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> num[i];
	}
	if (is_sorted(num+1, num+1+n)) {
		cout << 1;
		for (int i=2; i<=n; i++) {
			cout << " " <<i;
		}
		cout << '\n';
		return;
	}
	int l, r;
	for (int i=1; i<=n; i++) {
		if (num[i] != i) {
			l = i;
			break;
		}
	}
	for (int i=1; i<=n; i++) {
		if (num[i] == l) {
			r = i;
			break;
		}
	}
	while (l < r) {
		swap(num[l], num[r]);
		l++;
		r--;
	}
	cout << num[1];
	for (int i=2; i<=n; i++) {
		cout << " " << num[i];
	}
	cout << '\n';

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