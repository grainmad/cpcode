#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

void sol() {
	int n, d, l;
	cin >> n >> d >> l;
	int k = n/2;
	if (n%2) {
		int i;
		for (i=1; i<=l; i++) {
			if ((abs(d-i)+k-1)/k<l) break;
		}
		if (i > l) {
			cout << "-1";
		} else {
			cout << i << " ";
			for (int j=0; j<k; j++) {
				if (d-i>=0) {
					cout << "1 " << (abs(d-i)/k+(j<abs(d-i)%k))+1 << " ";
				} else {
					cout <<(abs(d-i)/k+(j<abs(d-i)%k))+1 << " 1 ";
				}
			}
		}
	} else {
		if ((abs(d)+k-1)/k>=l) {
			cout << "-1";
		} else {
			for (int i=0; i<k; i++) {
				if (d<0) {
					cout << "1 " << (abs(d)/k+(i<abs(d)%k))+1 << " ";
				} else {
					cout << (abs(d)/k+(i<abs(d)%k))+1 << " 1 ";
				}
			}
		}
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