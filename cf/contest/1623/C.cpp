//C
#include <bits/stdc++.h>
#define ll long long 
#define MAXN 200005
using namespace std;

ll num[MAXN];
ll cp[MAXN];

bool avl(int sz, int val) {
	for (int i=sz-1; i>=0; i--) {
		if (cp[i]<val) return false;
		if (i>=2) {
			int v = min(num[i], cp[i]-val)/3;
			cp[i] -= v*3;
			cp[i-1] += v;
			cp[i-2] += v*2;
		}
	}
	return true;
}

void sol() {
	int n, l=0, r=1e9+7, m;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> num[i];
	}
	while (l < r) {
		m = l+(r-l)/2;
		for (int i=0; i<n; i++) cp[i] = num[i];
		if (avl(n, m)) l = m+1;
		else r = m;
	}
	cout << r-1 << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
	return 0;
}

