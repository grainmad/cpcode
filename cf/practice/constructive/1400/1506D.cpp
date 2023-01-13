#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n; cin >> n;
	map<int,int> mp;
	for (int i=0; i<n; i++) {
		int x; cin >> x;
		mp[x]++;
	}
	priority_queue<int> que;
	for (auto i: mp) {
		que.push(i.second);
	}
	// cout << "00000"<< endl;
	while (que.size()>1) {
		int u = que.top(); que.pop();
		int v = que.top(); que.pop();
		if (u !=1) que.push(u-1);
		if (v !=1) que.push(v-1);
	}
	cout << (que.empty()?0:que.top()) << endl;

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