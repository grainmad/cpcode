//A
#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (n%2==1 && k>n/2+1 || n%2 == 0 && k>n/2) {
			cout << -1 << endl;
			continue;
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (i == j && i%2==0 && k!=0) {
					cout << "R";
					k--;
				}
				else cout << ".";
			}
			cout << endl;
		}
	}
	return 0;
}
