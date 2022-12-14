#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 3005
using namespace std;


void sol() {
	string s;
	int n, ans = 0; 
	cin >> n;
	cin >> s;
	for (int i=0; i<n; i++) {
		int a=0, b=0, c=0, p=-2;
		for (int j=i; j<n; j++) {
			if (s[j] == '-') a++;
			else b++;
			if (s[j] == '-') {
				if (p+1 == j) {
					c++;
					p = -2;
				} else {
					p = j;
				}
			}
			// cout << i << " " << j << endl;
			// cout << a << " " << b << " " << c << endl;
			if (a>=b && (a-b)%3 == 0 && (a-b)/3<=c) {
				ans++;
				// cout << "yes" << endl; 
			}
		}
	}
	cout << ans << endl;
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