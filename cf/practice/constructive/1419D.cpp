#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int v[N];

void sol() {
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a.rbegin(), a.rend());
	int sz = n%2?n:n-1;
	for (int i=0, p=0; i<sz; i+=2) v[i] = a[p++];
	for (int i=sz-2, p=a.size()-1; i>=0; i-=2) v[i] = a[p--];
	if (n%2==0) v[n-1] = a[n/2];
	int ans = 0;
	for (int i=1; i<sz-1; i++) {
		if (v[i-1]>v[i] && v[i]<v[i+1]) ans++;
	}
	cout << ans << "\n";
	for (int i=0; i<n; i++) cout << v[i] << " ";cout << "\n";
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