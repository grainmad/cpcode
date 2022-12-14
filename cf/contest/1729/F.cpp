#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

int p[N];
vector<int> v[9];

pair<int,int> gen(int l, int r, int k) {
	int rt1 = N, rt2 = N;
	int x = (p[r]-p[l-1])%9;
	for (int a=0; a<9; a++) {
		int b = (k-x*a%9+9)%9;
		if (a == b && v[a].size()>=2) {
			if (rt1 > v[a][0]) {
				rt1 = v[a][0];
				rt2 = v[a][1];
			} else if (rt1 == v[a][0] && rt2 > v[a][1]) {
				rt2 = v[a][1];
			}
		} else if (a != b && v[a].size() && v[b].size()) {
			if (rt1 > v[a][0]) {
				rt1 = v[a][0];
				rt2 = v[b][0];
			} else if (rt1 == v[a][0] && rt2 > v[b][0]) {
				rt2 = v[b][0];
			}
		}
	}
	if (rt1 == N) return {-1, -1};
	return {rt1, rt2};
}

void sol() {
	for (int i=0; i<9; i++) v[i].clear();
	
	string s;
	cin >> s;
	int w, m;
	cin >> w >> m;

	int n = s.size();
	for (int i=1; i<=n; i++) {
		p[i] = p[i-1] + (s[i-1]-'0');
	}
	for (int i=w; i<=n; i++) {
		v[(p[i]-p[i-w])%9].push_back(i-w+1);
	}
	for (int i=0; i<m; i++) {
		int l, r, k;
		cin >> l >> r >> k;
		auto pa = gen(l, r, k);
		cout << pa.first << " " << pa.second << endl;
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