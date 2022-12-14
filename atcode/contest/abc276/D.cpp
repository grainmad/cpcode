#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int f2[N], f3[N];

void sol() {
	int n;
	cin >> n;
	std::vector<int> v;
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		f2[i] = f3[i] = 0;
		while (x%2==0) {
			f2[i]++;
			x/=2;
		}
		while (x%3==0) {
			f3[i]++;
			x/=3;
		}
		v.push_back(x);
	}
	int ok = 1;
	for (int i:v) {
		if (i != v[0]) {
			ok = 0;
		}
	}
	if (!ok) {
		cout << "-1\n";
		return ;
	}
	int mn2 = *min_element(f2, f2+n);
	int mn3 = *min_element(f3, f3+n);
	int ans = 0;
	for (int i=0; i<n; i++) {
		ans += f2[i]-mn2;
		ans += f3[i]-mn3;
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