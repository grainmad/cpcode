#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 10005
using namespace std;

void sol() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n, 0);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int same = 1;
	for (int i=0; i<n; i++) {
		if (a[i] != a[0]) same = 0;
	}
	if (same) {
		cout << "0 0" << endl;
		return ;
	}
	vector<pair<int,int>> v;
	for (int i=0; i<k; i++) {
		int p = find(a.begin(), a.end(), *max_element(a.begin(), a.end()))-a.begin();
		int q = find(a.begin(), a.end(), *min_element(a.begin(), a.end()))-a.begin();
		if (p!=q) v.push_back({p+1, q+1});
		a[p]--;
		a[q]++;
	}
	cout << *max_element(a.begin(), a.end())-*min_element(a.begin(), a.end());
	cout << " " <<  v.size() << endl;
	for (auto i:v) {
		cout << i.first << " " << i.second << endl;
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