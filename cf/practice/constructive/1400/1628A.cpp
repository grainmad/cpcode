#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];
int st[N];

void sol() {
	std::vector<int> v;
	int n;
	cin >> n;
	for (int i=0; i<=n+1; i++) st[i] = 0;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		st[a[i]]++;
	}
	int p = 0;
	for (int i=0; i<=n+1; i++) {
		if (st[i] == 0) {
			p = i;
			break;
		} 
	}
	int idx = 0, np = p;
	while (p != 0) {
		std::vector<int> vis(p, 0);
		int cnt = 0;
		for (; idx<n && cnt!=p; idx++) {
			st[a[idx]]--;
			if (st[a[idx]]==0) np = min(np, a[idx]);
			if (a[idx]<p && !vis[a[idx]]) {
				cnt++;
				vis[a[idx]] = 1;
			}
		}
		v.push_back(p);
		p = np;
	}
	for (int i=idx; i<n; i++) {
		v.push_back(0);
	}
	cout << v.size() << endl;
	for (int i:v) {
		cout << i << " ";
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