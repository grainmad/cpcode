//12:33 13:07
#include <bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;

int n;
int h[N];

void sol() {
	cin >> n;
	for (int i=0; i<n; i++) cin >> h[i];
	sort(h, h+n);
	if (n == 2) {
		cout << h[0] << " " << h[1] << '\n';
		return;
	}
	int s = h[1]-h[0], e = h[n-1]-h[n-2];
	int p = (s<e ? 0 : n-2);
	for (int i=1; i<n; i++) {
		if (h[i]-h[i-1] < h[p+1]-h[p]) {
			p = i-1;
		}
	}
	cout << h[p+1];
	for (int i=p+2; i<n; i++) cout << " " << h[i];
	for (int i=0; i<p; i++) cout << " " << h[i];
	cout << " " << h[p] << '\n';
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