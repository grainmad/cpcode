#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 105
using namespace std;


void sol() {
	int n; cin >> n;
	std::vector<int> v;
	while (n) {
		int t = n, a=0, p = 1;
		while (t) {
			if (t%10) a+=p;
			t/=10; p*=10;
		}
		v.push_back(a);
		n-=a;
	}
	cout << v.size() << endl;
	for (int i:v) cout << i << " ";
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