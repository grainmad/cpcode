#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int y, x;
	cin >> y >> x;
	if (y-1<=x && x<=2*(y+1)) {
		if (y>=x) {
			for (int i=0; i<x+y; i++) {
				cout << (i%2);
			}
			cout << '\n';
		} else {
			int p = x-(y+1);
			if (p == 0) {
				for (int i=0; i<x+y; i++) {
					cout << (i%2?0:1);
				}
				cout << '\n';
				return;
			}
			cout << "11";
			for (int i=1; i<y+1; i++) {
				cout << (i<p?"011":"01");
			}
			cout << "\n";
		}
	} else {
		cout << "-1\n";
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