//22:59 23:30
#include <bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;

int n;
int a[N];

void sol() {
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	cout << 0;
	for (int i=1; i<n; i++) {
		int t = a[i-1]|a[i];
		cout << " " << (t^a[i]);
		a[i] = a[i-1]|a[i];
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