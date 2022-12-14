//A
#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m, rb, cb, rd, cd;
	cin >> t;
	while (t--) {
		cin >> n >> m >> rb >> cb >> rd >> cd;
		int r = rd >= rb? rd-rb:2*n-rb-rd;
		int c = cd >= cb? cd-cb:2*m-cb-cd;
		cout << min(r,c) << endl;
	}
	return 0;
}
