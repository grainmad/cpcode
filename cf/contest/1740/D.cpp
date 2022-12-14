#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, m, k;
	cin >> n >> m >> k;
	std::vector<int> v(k);
	for (int i=0; i<k; i++) cin >> v[i];
	priority_queue<int> que;
	int c = k;
	for (int i=0; i<k; i++) {
		que.push(v[i]);
		if (que.size() == m*n-2) {
			cout << "TIDAK\n";
			return ;
		}
		while (que.size() && que.top() == c) {
			que.pop();
			c--;
		}
	}
	cout <<"YA\n";
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