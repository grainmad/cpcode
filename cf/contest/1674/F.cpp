#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 1000005
using namespace std;

string g[1005];

// ll BIT[N];
// // ll xBIT[N];

// void bit_add(int x, ll val) {
//     for (int i=x; i<N; i+=i&-i) {
//         BIT[i] += val;       
//         // xBIT[i] += x*val;
//         // 区间查询时 BIT[i] += val; xBIT[i] += x*val;
//     }
// }

// ll bit_ps(int x) {
//     ll rt = 0;
//     for (int i=x; i>0; i-=i&-i) {
//         rt += BIT[i];
//         // rt += x*BIT[i]-xBIT[i];
//         // 区间查询时 rt += (x+1)*BIT[i]-xBIT[i];
//     }
//     return rt;
// }



void sol() {
	// priority_queue<int> v;
	int n, m, q;
	ll cnt = 0, pre = 0;
	cin >> n >> m >> q;
	for (int i=0; i<n; i++) cin >> g[i];
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			if (g[j][i] == '*') {
				// bit_add(i*n+j+1, 1);
				cnt++;
				// if (i*n+j+1<=cnt) pre++;
			}
		}
	}
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			if (g[j][i] == '*' && i*n+j+1<=cnt) {
				pre++;
			}
		}
	}
	// cout << "cnt " << cnt << endl;
	// cout << "pre " << pre << endl;
	for (int i=0; i<q; i++) {
		// cout << "cnt" << cnt << endl;
		int x, y;
		cin >> x >> y;
		x--; y--;
		if (g[x][y] == '.') {
			cnt++;
			// bit_add(y*n+x+1, 1);
			g[x][y] = '*';
			if (g[(cnt-1)%n][(cnt-1)/n] == '*') pre++;
			if (y*n+x+1 < cnt) pre++;
		} else {
			// bit_add(y*n+x+1, -1);
			if (g[(cnt-1)%n][(cnt-1)/n] == '*') pre--;
			cnt--;
			if (y*n+x+1 <= cnt) pre--;
			g[x][y] = '.';
		}
		// cout << "cnt " << cnt << endl;
		// cout << "pre " << pre << endl;
		// cout << cnt-bit_ps(cnt) << endl;
		cout << cnt - pre << endl;
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