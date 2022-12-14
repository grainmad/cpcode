#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;


void sol() {
	ll l, r, a;
	cin >> l >> r >> a;
	if (r/a*a>l) {
		cout << max(r/a-1+a-1, r/a+r%a) << endl;
	} else {
		cout << r/a+r%a << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}