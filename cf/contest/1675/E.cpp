#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	char mx = *max_element(s.begin(), s.end());
	if (k >= mx-'a') {
		for (int i=0; i<n; i++) cout << 'a';
		cout << endl;
		return;
	}
	mx = 'a';
	for (int i=0; i<n; i++) {
		if (k>=s[i]-'a') mx = max(mx, s[i]);
		else {
			//s[i] 是 第一个大于k的数，mx 是s[i]之前所有小于k的最大值，我们对它操作。k还剩k-mx
			for (char& j:s) {
				if (j <= mx) j = 'a';
			}
			k -= mx-'a';
			char cur = s[i], to = s[i]-k;
			for (char& j:s) {
				if (j <= cur) {
					j = min(j, to);
				}
			}
			break;
		}
	}
	cout << s << endl;

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