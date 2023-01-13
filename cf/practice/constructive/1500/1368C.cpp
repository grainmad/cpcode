#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;
/*

    # @ 
  # @ # @
# @ # @ # @
@ # @ # @ # @
  @ # @ # @ #
    @ # @ #
      @ #
*/

void sol() {
	int n;
	cin >> n;
	int mn = N, x, y;
	for (int i=1; i<=n; i++) {
		if ((n+i)%(2*i-1) == 0) {
			if (i+(n+i)/(2*i-1)<mn) {
				mn = i+(n+i)/(2*i-1);
				x = i; y = (n+i)/(2*i-1);
			}
		}
	}
	// cout << x << " " << y << endl;
	cout << n+2*(x+y) << "\n";
	for (int i=0; i<x; i++) {
		for (int j=0; j<y+1; j++) {
			cout << (i+j) << " " << i-j << "\n";
		}
	}
	for (int i=0; i<y; i++) {
		for (int j=0; j<x+1; j++) {
			cout << (i+j) << " " << (j-i-1) << "\n";
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