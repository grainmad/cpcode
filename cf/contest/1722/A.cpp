#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

string s = "Timur";

void sol() {
	int n;
	string p;
	cin >> n >> p;
	sort(p.begin(), p.end());
	cout << (s==p?"YES\n":"NO\n");
}

int main() {
	sort(s.begin(), s.end());
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