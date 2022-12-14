#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 505
#define MOD 998224353
using namespace std;

int a[N][N];
int ans[N][N];

void sol() {
	int H, W, n, h, w;
	map<int,int> mp;
	cin >> H >> W >> n >> h >> w;
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			cin >> a[i][j];
			mp[a[i][j]]++;
		}
	}
	for (int i=0; i<=H-h; i++) {
		for (int x=i; x<i+h; x++) {
			for (int y=0; y<w; y++) {
				if (--mp[a[x][y]] == 0) mp.erase(a[x][y]);
			}
		}
		ans[i][0] = (int)mp.size();
		for (int j=1; j<=W-w; j++) {	
			for (int x=i; x<i+h; x++) {
				mp[a[x][j-1]]++;
				if (--mp[a[x][j+w-1]] == 0) mp.erase(a[x][j+w-1]);
			}
			ans[i][j] = (int)mp.size();
		}
		for (int x=i; x<i+h; x++) {
			for (int y=W-w; y<W; y++) {
				mp[a[x][y]]++;
			}
		}
	}
	for (int i=0; i<=H-h; i++) {
		for (int j=0; j<=W-w; j++) {
			cout << ans[i][j] << " ";
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