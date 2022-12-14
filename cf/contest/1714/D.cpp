#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	string t, s[11]; int n;
	cin >> t;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> s[i];
	}
	std::vector<pair<int,int>> v;
	int p = 0, sz = t.size();
	while (p < sz) {
		// cout << p << endl;
		int id, idx, q = p;
		for (int i=max(0, p-10); i<=p; i++) {
			for (int j=0; j<n; j++) {
				int ed = i+int(s[j].size());
				if (ed > sz) continue;
				int ok = 1;
				for (int k=i; k<ed; k++) {
					if (s[j][k-i] != t[k]) {ok = 0; break;}
				}
				if (ok && ed>q) {
					q = ed;
					id = j;
					idx = i;
				}
			}
		}
		// cout << id << " " << idx << " " << q << endl;
		if (q == p) {
			cout << "-1\n";
			return ;
		}
		p = q;
		v.push_back({id, idx});
	}
	cout << v.size() << "\n";
	for (auto i:v) {
		cout << i.first+1 << " " << i.second+1 << "\n";
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