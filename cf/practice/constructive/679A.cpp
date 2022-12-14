#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int v[105];

void sol() {
	int cnt = 0, p;
	for (int i=2; i<=10; i++) {
		if (!v[i]) {
			cout << i << endl;
			string s; cin >> s;
			if (s == "no") {
				for (int j=i; j<=100; j+=i) v[j] = 1;
			} else cnt++, p = i;
		}
	}
	if (cnt == 0) cout << "prime" << endl;
	else if (cnt >= 2) cout << "composite" << endl;
	else {
		for (int i=2*p; i<=100; i+=p) {
			if (v[i]) continue;
			cout << i << endl;
			string s; cin >> s;
			if (s == "no") {
				for (int j=i; j<=100; j+=i) v[j] = 1;
			} else {
				cout << "composite" << endl;
				return ;
			}
		}
		cout << "prime" << endl;
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