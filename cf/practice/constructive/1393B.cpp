#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
using namespace std;

int a[N];

void sol() {
	int n, q, cnt2=0, cnt4=0;
	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		cnt2 -= a[x]/2;
		cnt4 -= a[x]/4;
		a[x]++;
		cnt2 += a[x]/2;
		cnt4 += a[x]/4;
	}
	cin >> q;
	for (int i=0; i<q; i++) {
		string s; int x;
		cin >> s >> x;
		cnt2 -= a[x]/2;
		cnt4 -= a[x]/4;
		if (s == "+") {
			a[x]++;
		} else a[x]--;
		cnt2 += a[x]/2;
		cnt4 += a[x]/4;
		if (cnt4 >= 1 && cnt2 >= 4) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
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