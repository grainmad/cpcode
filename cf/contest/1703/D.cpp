#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	std::vector<string> v(n);
	set<string> st;
	std::vector<int> ok(n, 0);
	for (int i=0; i<n; i++) {
		cin >> v[i];
		st.insert(v[i]);
	}
	int p = 0;
	for (auto& i:v) {
		for (int j=1; j<i.size(); j++) {
			if (st.count(i.substr(0,j)) && st.count(i.substr(j))) {
				ok[p] = 1;
				break;
			} 
		}
		p++;
	}
	for (int i:ok) {
		cout << i;
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