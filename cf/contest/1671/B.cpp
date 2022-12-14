#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];


void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	int cnt1=0, cnt2=0, ok = 1;
	for (int i=1; i<n; i++) {
		if (a[i]-a[i-1] == 2) cnt1++;
		else if (a[i]-a[i-1] == 3) cnt2++;
		else if (a[i]-a[i-1] > 3) ok = 0;
	}
	if (ok == 0) cout << "NO" << endl;
	else if (cnt2 == 1 && cnt1 == 0) cout << "YES" << endl;
	else if (cnt2 == 0 && cnt1 <= 2) {
		cout << "YES" << endl;
	} else cout << "NO" << endl;
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