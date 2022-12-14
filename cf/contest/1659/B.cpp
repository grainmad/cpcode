#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int opt[N];

void sol() {
	int n, k;
	cin >> n >> k;
	for (int i=0; i<=n; i++) opt[i] = 0;
	string s;
	cin >> s;
	std::vector<int> p0, p1;
	for (int i=0; i<n; i++) {
		if (s[i] == '0') p0.push_back(i+1);
		else p1.push_back(i+1);
	}
	if (k%2 == 1) {
		if (k>p1.size()) {
			for (int i=0; i<n-1; i++) cout << "1";
			cout << (p1.size()%2?"1":"0") << endl;
		} else {
			int ed = p1[k-1];
			for (int i=0; i<ed; i++) cout << "1";
			for (int i=ed; i<n; i++) {
				if (s[i] == '1') cout << '0';
				else cout << '1';
			}
			cout << endl;
		}
		for (int i=0; i<k; i++) {
			if (i < p1.size()) opt[p1[i]]++;
			else {
				opt[n] += k-i;
				break;
			}
		}
		for (int i=1; i<=n; i++) {
			cout << opt[i] << " ";
		} cout << endl;
	} else {
		if (k>p0.size()) {
			for (int i=0; i<n-1; i++) cout << "1";
			cout << (p0.size()%2?"0":"1") << endl;
		} else {
			int ed = k-1>=0? p0[k-1]:0;
			for (int i=0; i<ed; i++) cout << "1";
			for (int i=ed; i<n; i++) {
				cout << s[i];
			}
			cout << endl;
		}
		for (int i=0; i<k; i++) {
			if (i < p0.size()) opt[p0[i]]++;
			else {
				opt[n] += k-i;
				break;
			}
		}
		for (int i=1; i<=n; i++) {
			cout << opt[i] << " ";
		} cout << endl;
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