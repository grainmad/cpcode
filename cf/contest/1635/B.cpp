#include <bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;

int n;
int a[N];

void sol() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	for (int i=1; i<n-1; i++) {
		if (a[i-1]<a[i] && a[i]>a[i+1]) {
			cnt++;
			a[i+1] = a[i];
			if (i+2<n && a[i+2]>a[i+1]) a[i+1] = a[i+2];
		}
	}
	cout << cnt << '\n';
	cout << a[0];
	for (int i=1; i<n; i++) {
		cout << " " << a[i];
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