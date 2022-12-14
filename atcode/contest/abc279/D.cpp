#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

double a, b;

double cal (double x) {
	return b*x+a/sqrt(x+1);
}


void sol() {
	cin >> a >> b;
	if (b>a) {
		printf("%.10lf\n", cal(0));
		return ;
	}
	ll l = l, r = 1e18+7;
	double lans, rans;
	while(l<=r) {
	    double lmid = l + (r - l) / 3;
	    double rmid = r - (r - l) / 3;
	    lans = cal(lmid), rans = cal(rmid);
	    
	    // 求凹函数的极小值
	    if(lans <= rans) r = rmid-1;
	    else l = lmid+1;
	    
	    // // 求凸函数的极大值
	    // if(lans >= rans) l = lmid;
	    // else r = rmid;
	}
	// 输出 l 或 r 都可

	printf("%.10lf\n", min(lans, rans));
}

int main() {
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