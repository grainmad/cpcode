#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 1005
using namespace std;

int a[N];
std::vector<int> prime = {2,3,5,7,11,13,17,19,23,29,31};

void sol() {
	int n; cin >> n;
	vector<int> v(n, 0);
	int cnt = n;
	int p = 1;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i:prime) {
		int ok = 0;
		for (int j=0; j<n; j++) {
			if (a[j]%i == 0 && v[j] == 0) {
				ok = 1;
				v[j] = p;
				cnt--;
			}
		}
		if (ok) p++;
		if (cnt == 0) break;
	}
	cout << *max_element(v.begin(), v.end()) << endl;
	for (int i:v) {
		cout << i << " ";
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