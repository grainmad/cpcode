//A
#include <bits/stdc++.h> 

using namespace std;

int st[205];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, num;
	cin >> t;
	while (t--) {
		memset(st, 0, sizeof(st));
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> num;
			if (st[num+100] == 0) st[num+100] = 1;
			else st[100-num] = 1;
		}
//		for (int i=0; i<=200; i++) {
//			cout << 
//		}
		int ans = 0;
		for (int i=0; i<=200; i++) {
			if (st[i] == 1) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
