#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 5005
using namespace std;

int num[N];

void sol() {
	int n; cin >> n;
	for (int i=0; i<n; i++) cin >> num[i];
	for (int i=0; i<n; i++) {
		int x; string s;
		cin >> x >> s;
		for (char j:s) {
			if (j == 'D') num[i] = (num[i]+1)%10;
			else num[i] = (num[i]+9)%10;
		}
	}
	for (int i=0; i<n; i++) {
		cout << num[i] << " ";
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