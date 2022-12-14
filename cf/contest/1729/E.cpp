#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int i=1;
	while (i) {
		ll x, y;
		cout << "? " << i << " " << i+1 << endl;
		cin >> x;
		cout << "? " << i+1 << " " << i << endl;
		cin >> y;
		if (x != y && x != -1 && y != -1) {
			cout << "! " << x + y << endl;
			return ;
		}
		i++;
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