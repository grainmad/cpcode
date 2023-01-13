//12:22 14:08
#include <bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;

int a[N];
int ans[N];
int n;

void sol() {
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	if (a[n-1] != n && a[0] != n) {
		cout << "-1\n";
		return ;
	}
	if (n == 1) {
		cout << a[0] << '\n';
		return ;
	}
	int l = 0, r = 1, al=0, ar=n-1;
	while (l!=r) {
		if (a[l] < a[r]) {
			ans[al++] = a[l];
			l = (l-1+n)%n;
		}else {
			ans[ar--] = a[r];
			r = (r+1)%n;
		}
	}
	ans[al] = a[l];
	cout << ans[0];
	for (int i=1; i<n; i++) {
		cout << " " << ans[i];
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