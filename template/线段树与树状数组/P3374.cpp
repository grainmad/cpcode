#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;
ll BIT[N];
// ll xBIT[N];

void bit_add(int x, ll val) {
    for (int i=x; i<N; i+=i&-i) {
        BIT[i] += val;       
        // xBIT[i] += x*val;
        // 维护差分时 BIT[i] += val; xBIT[i] += x*val;
    }
}

ll bit_ps(int x) {
    ll rt = 0;
    for (int i=x; i>0; i-=i&-i) {
        rt += BIT[i];
        // rt += x*BIT[i]-xBIT[i];
        // 维护差分时 rt += (x+1)*BIT[i]-xBIT[i];
    }
    return rt;
}

//BIT 维护a
//单点修改：bit_add(x, val) 下标x增加val
//前缀和：  bit_ps(x) a[1...x]的前缀和

// BIT 维护a的差分
//区间修改：a[x...y]增加val， bit_add(x, val), bit_add(y+1, val);
//前缀和：  bit_ps(x) a[1...x]的前缀和

/*
区间修改原理
a 原数组，d 差分数组，p 前缀数组 
a[0] = d[0] = p[0] = 0

d[i] = a[i] - a[i-1]
a[i] = p[i] - p[i-1]

Σd[i] = a[n], i ∈[1,n]
Σa[i] = p[n], i ∈[1,n]
ΣΣd[j] = p[n], j ∈[1,i], i ∈[1,n]
p[n] = (n+1)Σd[i]-Σd[i]*i

*/


void sol() {
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		// bit_add(i, x);
		BIT[i] += x;
		if (i+(i&-i) < N) BIT[i+(i&-i)] += BIT[i];
	}
	for (int i=0; i<m; i++) {
		int opt, x, y;
		cin >> opt >> x >> y;
		if (opt == 1) {
			bit_add(x, y);
		} else {
			cout << bit_ps(y)-bit_ps(x-1) << endl;
		}
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