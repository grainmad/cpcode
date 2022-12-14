#include <bits/stdc++.h>
#define MAXN 200005
#define ll long long
using namespace std;

int num[MAXN];

void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> num[i];
	}
	for (int i=0; i<n/2; i++) {
		swap(num[i], num[n-1-i]);
	}
	int p = 0;
	for (int i=0; i<n; i++) {
		if (num[i] == num[0]) p++;
		else break;
	}
	int k=n-1;
	while (k>=0 && num[k] == num[0]) k--;
	if (k == -1) {
		cout << "0" << endl;
		return ;
	}
	k = k+1;
	int ans = 0;
	while (p<k) {
		p = 2*p;
		while (p < n && num[p] == num[0]) p++;
		ans++;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		sol();
	}
	return 0;
}