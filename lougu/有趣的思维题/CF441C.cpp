#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int n, m, k;

void sol() {
	cin >> n >> m >> k;
	int itv = n*m%k+n*m/k, cnt = 0;
	bool fs = true;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (fs) {
				if (cnt == 0) cout << itv << " ";
				if (cnt < itv) {
					cout << i+1 << " " << (i%2?m-j-1:j)+1 << " ";
					cnt++;
					if (cnt == itv) {	
						cout << endl;
						fs = false;
						itv = n*m/k;
						cnt = 0;
					}	
				} 
			} else {
				if (cnt == 0) cout << itv << " ";
				if (cnt < itv) {
					cout << i+1 << " " << (i%2?m-j-1:j)+1 << " ";
					cnt++;
					if (cnt == itv) cnt = 0, cout << endl;
				} 
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// int t;
	// cin >> t;
	// while (t--) {
	// 	sol();
	// }
	sol();
	return 0;
}