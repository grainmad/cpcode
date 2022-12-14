#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998224353
using namespace std;
//[HNOI2008]玩具装箱

/*

形如 dp_i = \min_{j<i} {dp_j + f_i\cdot g_j + h_i + v_j} 的状态转移方程。
可以使用斜率优化, 其中 f_i, h_i 是i的函数, g_j, v_j是j的函数

移项
dp_i-h_i = \min_{j<i} {dp_j + v_j + f_i \cdot g_j}

令b_i = dp_i-h_i, y_j = dp_j+v_j, x_j = g_j， k_i = -f_i
得到 b_i = \min_{j<i} {y_j - k_i \cdot x_j}
对于每个确定的i，b_i和k_i是常量，x_j和y_j是变量。
我们需要让b_i最小，我们知道一次函数y=kx+b中b是截距，k是斜率。
对于已经确定斜率让截距最小就会让dp最小。
当k_i是单调的（假设是单调上升的）。我们求出(x_j,y_j)的下凸包，
让一根斜率为k_i的直线由下向上扫遇到第一个(x_p,y_p)就是最优的决策点。
最优决策点与之前的点连线斜率不会大于k_i，即s<p, \frac{y_p-y_s}{x_p-x_s} \le k_i;
最优决策点与之后的点连线斜率大于k_i，即p<e, \frac{y_p-y_e}{x_p-x_e} > k_i;
基于这两条特点可以维护一个斜率递增的单调队列
对于求dp_i，先移除队列中斜率小于k_i的点，那么队首就是最有决策点。
然后移除队尾不满足单调性的点再将当前决策点加入队列。


*/
ll k; 

ll b, e;
ll s[N], dp[N], q[N];

ll X(ll x) {
	return s[x];
}
ll Y(ll x) {
	return dp[x]+s[x]*s[x]+2*s[x]*k;
}
ll K(ll x) {
	return 2*s[x];
}

double slope(ll x, ll y) {
	return 1.0*(Y(x)-Y(y))/(X(x)-X(y));
}

void sol() {
	int n, l;
	cin >> n >> l;
	k = l+1;
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		s[i] = s[i-1]+x+1;
	}
	for (int i=1; i<=n; i++) {
		while (b<e && slope(q[b], q[b+1]) <= K(i)) b++;
		dp[i] = dp[q[b]] + (s[i]-s[q[b]]-k)*(s[i]-s[q[b]]-k);
		while (b<e && slope(q[e], q[e-1]) >= slope(q[e], i)) e--;
		q[++e] = i;
	}
	cout << dp[n] << endl;
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