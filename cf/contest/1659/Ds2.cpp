#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

ll c[N];
ll a[N];
int dif[N];

void sol() {
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> c[i];
		dif[i] = 0;
	}
	ll k = accumulate(c+1, c+n+1, 0LL)/n;
	int s = 0;
	for (int i=n; i>0; i--) {
		ll v = c[i] + s + dif[i];
		if (v == i) {
			a[i] = 1;
			dif[i]--; dif[i-k]++;
			k--;
		} else {
			a[i] = 0;
			dif[i]--; dif[i-k]++;
		}
		s += dif[i];
	}
	for (int i=1; i<=n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef SINGLE_INPUT
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
#else
	sol();
#endif
	return 0;
}