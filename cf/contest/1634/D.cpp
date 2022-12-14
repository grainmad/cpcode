#include <bits/stdc++.h>

using namespace std;

struct Node {
	int num;
	int w;
	bool operator<(Node& o) {
		return w > o.w;
	}
};



void sol() {
	queue<int> que;
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) que.push(i);
	while (que.size() != 2) {
		int sz = 4;
		int a[sz], d[sz];
		Node v[sz];
		for (int i=0; i<sz; i++) {
			a[i] = que.front();
			que.pop();
		}
		for (int i=0; i<sz; i++) {
			v[i].num = a[i];
			v[i].w = 0;
		}
		for (int i=0; i<sz; i++) {
			cout << "?";
			for (int j=0; j<sz; j++) {
				if (j != i) {
					cout << " " << a[j];
				}
			}
			cout << endl;
			cin >> d[i];
		}
		int mx = -1;
		for (int i=0; i<sz; i++) {
			mx = max(mx, d[i]);
		}
		for (int i=0; i<sz; i++) {
			if (d[i] == mx) {
				for (int j=0; j<sz; j++) {
					if (j != i) v[j].w++;
				}
			}
		}
		sort(v, v+sz);
		// for (int i=0; i<4; i++) {
		// 	cout << v[i].num << " " << v[i].w << endl;
		// }
		que.push(v[0].num);
		que.push(v[1].num);
		if (que.size() == 3) que.push(v[2].num);
	}
	cout << "!";
	cout << " " << que.front();
	que.pop();
	cout << " " << que.front() << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		sol();
	}
	return 0;
}