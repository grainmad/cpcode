#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int n, m, k;
int x=1, y=1;

pair<int,int> get_pos() {
	pair<int,int> rt = {x, y};
	if (x%2==1 && y == m || x%2==0 && y == 1) x++;
	else if (x%2) y++;
	else y--;
	return rt;
}

void sol() {
	cin >> n >> m >> k;
	for (int i=0; i<k; i++) {
		int sz = n*m/k+(i<n*m%k?1:0);
		cout << sz << " ";
		for (int j=0; j<sz; j++) {
			auto p = get_pos();
			cout << p.first << " " << p.second << " ";
		}
		cout << "\n";
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