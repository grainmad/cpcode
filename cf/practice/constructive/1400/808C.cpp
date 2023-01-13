#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int ans[N];

void sol() {
	int n, w;
	cin >> n >> w;
	std::vector<pair<int,int>> v(n);
	int hf = 0;
	for (int i=0; i<n; i++) {
		cin >> v[i].first;
		v[i].second = i;
		hf += (v[i].first+1)/2;
	}
	if (hf > w) {
		cout << "-1" << endl;
		return ;
	}
	sort(v.rbegin(), v.rend());
	int re = w-hf;
	for (int i=0; i<n; i++) {
		int h = v[i].first;
		ans[v[i].second] = (h+1)/2;
		if (re>0) {
			if (re>=h-(h+1)/2) {
				re -= h-(h+1)/2;
				ans[v[i].second] = h;
			} else {
				ans[v[i].second] += re;
				re = 0;
			}
		}
	}
	for (int i=0; i<n; i++) {
		cout << ans[i] << " ";
	} cout << endl;
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