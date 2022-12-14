#include <bits/stdc++.h>
#define ll long long
#define N 2005
using namespace std;


ll u[10], d[10], l[10], r[10];
ll ans[10];
string g[N];

void sol() {
	for (int i=0; i<10; i++) {
		u[i] = d[i] = l[i] = r[i] = -1;
		ans[i] = 0;
	}
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> g[i];
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			int x = g[i][j]-'0';
			if (u[x] == -1 || i<u[x]) u[x] = i;
			if (d[x] == -1 || i>d[x]) d[x] = i;
			if (l[x] == -1 || j<l[x]) l[x] = j;
			if (r[x] == -1 || j>r[x]) r[x] = j;
		}
	}
	// for (int i=0; i<10; i++) {
	// 	cout << i << " u:" << u[i] << " d:" << d[i] << " l:" << l[i] << " r:" << r[i] << endl;
	// }
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			int x = g[i][j]-'0';
			ans[x] = max(ans[x], max(n-i-1, i)*max(j-l[x], r[x]-j));
			ans[x] = max(ans[x], max(n-j-1, j)*max(i-u[x], d[x]-i));
		}
	}
	for (int i=0; i<10; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
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
	return 0;
}