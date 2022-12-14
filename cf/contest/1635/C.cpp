#include <bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;

int n;
ll a[N];

void sol() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	if (is_sorted(a, a+n)) {
		cout << "0\n";
		return ;
	}
	if (a[n-1]<a[n-2] || a[n-1]<0) {
		cout << "-1\n";
		return;
	}
	cout << n-2 << '\n';
	for (int i=n-3; i>=0; i--) {
		cout << i+1 << " " << i+2 << " " << n << '\n';
	}
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