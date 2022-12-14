//C
#include <bits/stdc++.h>
#define N 505
#define ll long long
using namespace std;

ll dp[N][N];// dp[i][j] 代表到删除i个站牌, 第j站时（j从0开始），得到的最小时间 

int d[N];
int a[N];

int main() {
	memset(dp, 0x3f, sizeof(dp));
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n, l, k;
	cin >> n >> l >> k;
	for (int i=0; i<n; i++) {
		cin >> d[i];
	}
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	d[n] = l;
//	for (int i=0; i<=k; i++) {
//		dp[i][0] = 0;
//		psp[i][0] = a[0];
//	}
	dp[0][0] = 0;
	for (int i=1; i<=n; i++) {
		dp[0][i] = dp[0][i-1] + 1LL*(d[i]-d[i-1])*a[i-1];
	}
//	for (int i=0; i<=n; i++) {
//		cout << dp[0][i] << " ";
//	}
	for (int i=0; i<=k; i++) {
		for (int j=i; j<=n; j++) {//i<=j
			for (int p=1; i+p-1<=k && p+j<=n; p++) {
				dp[i+p-1][j+p] = min(dp[i+p-1][j+p], dp[i][j]+1LL*(d[p+j]-d[j])*a[j]);
			} 
		}
	}
//	for (int i=0; i<=k; i++) {
//		for (int j=0; j<=n; j++) {
//			cout << dp[i][j] << " ";
//		}cout << endl;
//	}
	ll ans = dp[k][n];
	for (int i=0; i<=k; i++) {
		ans = min(ans, dp[i][n]);
	}
	cout << ans << endl;
	return 0;
}
