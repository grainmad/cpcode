#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

ll a[N];


void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	std::vector<int> z(1, -1);
	for (int i=0; i<n; i++) {
		if (a[i] == 0) z.push_back(i);
	}
	z.push_back(n);
	int l = 0, r = -1, mx = 0;
	// for (int i=0; i<z.size(); i++) cout << z[i] << " ";
	// 	cout << endl << endl;
	for (int i=0; i<z.size()-1; i++) {
		int cnt = 0, neg = 0, fn=-1, ln=-1;
		for (int j=z[i]+1; j<z[i+1]; j++) {
			if (abs(a[j]) == 2) cnt++;
			if (a[j]<0) {
				neg++;
				if (fn == -1) fn = j;
				ln = j;
			}
		}
		// cout << cnt << " " << neg << " "  << " " << fn << " " << ln << endl;
		if (neg%2 == 0) {
			if (cnt>mx) {
				mx = cnt;
				l = z[i]+1;
				r = z[i+1]-1;
			}
		} else {
			int lcnt = 0, rcnt = 0;
			for (int j=z[i]+1; j<=fn; j++) {
				if (abs(a[j]) == 2) lcnt++;
			}
			for (int j=ln; j<z[i+1]; j++) {
				if (abs(a[j]) == 2) rcnt++;
			}
			// cout << lcnt << " " << rcnt << endl;
			if (cnt-lcnt > cnt-rcnt) {
				if (cnt-lcnt > mx) {
					mx = cnt-lcnt;
					l = fn+1;
					r = z[i+1]-1;
				}
			} else {
				if (cnt-rcnt > mx) {
					mx = cnt-rcnt;
					l = z[i]+1;
					r = ln-1;
				}
			}
		}
	}
	// cout << l << " -- " << r << endl; 
	cout << l << " " << n-r+-1 << endl;

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