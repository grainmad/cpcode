#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int n, m;
int cnt[N];//cnt[i] 颜色i的个数
int pos[N];

void sol() {
	cin >> n >> m;
	vector<vector<int>> tab(n, vector<int>(m, 0));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> tab[i][j];
			cnt[tab[i][j]]++;
		}
	}
	ll ans = 0; 
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			int c = tab[i][j];
			// cout << "i:"<<i << " j:" << j << "c:"<< c <<" pos:" << pos[c] << " cnt:" << cnt[c] << " attr:" << (2*pos[c] - cnt[c]  + 1)*(i) << endl;
			ans += (2LL*pos[c] - cnt[c]  + 1)*(i);
			pos[c]++;
		}
	}
	// cout << ans << endl;
	for (int i=0; i<N; i++) pos[i] = 0;
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			int c = tab[j][i];
			// cout << "i:"<<i << " j:" << j << "c:"<< c <<" pos:" << pos[c] << " cnt:" << cnt[c] << " attr:" << (2*pos[c] - cnt[c]  + 1)*(i) << endl;
			ans += (2LL*pos[c] - cnt[c] + 1)*(i);
			pos[c]++;
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// int t;
	// cin >> t;
	// while (t--) {
	// 	sol();
	// }
	sol();
}