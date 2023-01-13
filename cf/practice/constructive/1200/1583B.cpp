#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int n, m;
int a, b, c;
int st[N];

void sol() {
	cin >> n >> m;
	for (int i=1; i<=n; i++) st[i] = 0;
	for (int i=0; i<m; i++) {
		cin >> a >> b >> c;
		st[b] = 1;
	}
	for (int i=1; i<=n; i++) {
		if (st[i] == 0) {
			for (int j=1; j<=n; j++) {
				if (i != j) {
					cout << i << " " << j << '\n';
				}
			}
			break;
		}
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