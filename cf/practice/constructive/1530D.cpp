#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

int a[N];
int in[N];
void sol() {
	int n, cnt=0; cin >> n;
	for (int i=1; i<=n; i++) in[i] = 0;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		in[a[i]]++;
	}
	vector<int> v;
	for (int i=1; i<=n; i++) {
		if (in[i]) cnt += in[i]-1;
		else v.push_back(i);
	}
	cout << n-cnt << "\n";
	for (int i=1; i<=n; i++) {
		if (in[a[i]]>1) {
			if (i == v.back() && v.size()>1) swap(v[v.size()-2], v.back());
			if (i != v.back()) {
				in[a[i]]--;
				a[i] = v.back();
				v.pop_back();
			}
		}
	}
	for (int i=1; i<=n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
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