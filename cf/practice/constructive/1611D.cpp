#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int b[N];
int p[N];
int dis[N];

void sol() {
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) dis[i] = -1;
	for (int i=1; i<=n; i++) cin >> b[i];
	for (int i=1; i<=n; i++) cin >> p[i];
	dis[p[1]] = 0;	
	for (int i=2; i<=n; i++) {
		if (dis[b[p[i]]] == -1) {
			cout << "-1\n";
			return;
		}
		dis[p[i]] = dis[p[i-1]] + 1;
	}
	for (int i=1; i<=n; i++) {
		cout << dis[i] - dis[b[i]] << " ";
	}
	cout << "\n";
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