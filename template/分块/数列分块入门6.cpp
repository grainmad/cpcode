#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define M 350

int n, s, sz;
vector<int> a[M];


void update(int x, int val) {
	int cnt = 0;
	for (int i=0; i<sz; i++) {
		int aisz = a[i].size();
		cnt += aisz;
		if (x <= cnt) {
			a[i].insert(a[i].begin()+(aisz-1-cnt+x), val);
			return ;
		}
	}
}

int query(int x) {
	int cnt = 0;
	for (int i=0; i<sz; i++) {
		int aisz = a[i].size();
		cnt += aisz;
		if (x <= cnt) {
			return a[i][aisz-1-cnt+x];
		}
	}
	return -1;
}


int main() {
	cin >> n;
	s = sqrt(n);
	sz = (n+s-1)/s;
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		a[i/s].push_back(x);
	}
	// for (int i=0; i<sz; i++) {
	// 	cout << "v " << i << endl;
	// 	for (int j:a[i]) cout << j << " "; cout << endl;
	// }
	for (int i=0; i<n; i++) {
		int opt, l, r, c;
		cin >> opt >> l >> r >> c;
		if (opt) {
			cout << query(r) << endl;
		} else {
			update(l, r);
		}
	}
	return 0;
}