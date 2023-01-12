#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 300005
#define MAXN 550
#define MOD 998244353
using namespace std;


std::vector<int> g[N*2];
int pre[N*2], vis[N*2];

bool nprime[MAXN];
vector <int> prime;


void get_prime() {
	memset(nprime, 0, sizeof(nprime));
	int n = (int) sqrt(MAXN+0.5);
	for (int i=2; i<n; i++) {
		if (!nprime[i]) {
			for (int j=i*i; j<MAXN; j+=i) {
				nprime[j] = true;
			}
		}
	}
	for (int i=2; i<MAXN; i++) {
		if (!nprime[i]) {
			prime.push_back(i);
			// cout << i << endl;
		}
	}
	// cout << prime.size();
}


void sol() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin >> a[i];
	int x, y;
	cin >> x >> y;
	x--; y--;
	for (int i=0; i<a.size(); i++) {
		int u = a[i];
		for (int j:prime) {
			if (u%j) continue;
			g[N+j].push_back(i);
			g[i].push_back(N+j);
			while (u%j == 0) {
				u/=j;
			}
		}
		if (u != 1) {
			g[N+u].push_back(i);
			g[i].push_back(N+u);
		}
	}

	queue<int> q;
	q.push(y);
	vis[y] = 1;
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i:g[u]) {
			if (!vis[i]) {
				vis[i] = 1;
				pre[i] = u;
				q.push(i);
			}
		}
	}
	if (vis[x] == 0) {
		cout << "-1\n";
		return ;
	}
	vector<int> stp;
	while (x != y) {
		if(x<N) stp.push_back(x+1);
		x = pre[x];
	}
	stp.push_back(y+1);
	cout << stp.size() << "\n";
	for (int i:stp) {
		cout << i << " ";
	}
	cout << "\n";

}

int main() {
	get_prime();
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