#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

int a[N];

void add(int x) {
	for (int i=x; i<N; i+=i&-i) {
		a[i]++;
	}
}

int ask(int x) {
	int rt = 0;
	for (int i=x; i; i-=i&-i) {
		rt += a[i];
	}
	return rt;
}

void sol() {
	int n, x;
	ll ans = 0;
	cin >> n;
	for (int i=1; i<=n; i++) a[i] = 0; 
	for (int i=1; i<=n; i++) {
		cin >> x;
		if (x < i) {
			add(i);
			if (x>0) ans += ask(min(x-1, n));
			// cout<< x-1 << " " << ask(x-1) << endl;
		}
	}
	cout << ans << endl;
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