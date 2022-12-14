#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 600005
#define T 32
using namespace std;

struct BIT {
	ll BIT[N];
	// ll xBIT[N];

	void bit_add(int x, ll val) {
	    for (int i=x; i<N; i+=i&-i) {
	        BIT[i] += val;       
	        // xBIT[i] += x*val;
	        // 区间查询时 BIT[i] += val; xBIT[i] += x*val;
	    }
	}

	ll bit_ps(int x) {
	    ll rt = 0;
	    for (int i=x; i>0; i-=i&-i) {
	        rt += BIT[i];
	        // rt += x*BIT[i]-xBIT[i];
	        // 区间查询时 rt += (x+1)*BIT[i]-xBIT[i];
	    }
	    return rt;
	}
} bit[T];


int a[N];
int sl[T][N];

map<int,int> mp;
int cnt;
int id(int x) {
	if (mp.count(x)) return mp[x];
	return mp[x] = ++cnt;
}

void sol() {
	random_device rd;
	mt19937 mt(rd());
	int n, q;
	cin >> n >> q;
	for (int i=0; i<T; i++) {
		for (int j=1; j<=n+q; j++) {
			sl[i][j] = mt()%2;
		}
	}
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		int x = id(a[i]);
		for (int j=0; j<T; j++) {
			if (sl[j][x]) bit[j].bit_add(i,1);
		}
	}
	for (int j=0; j<q; j++) {
		int opt; cin >> opt;
		if (opt==1) {
			int i, x; cin >> i >> x;
			int prex = id(a[i]);
			a[i] = x;
			x = id(x);
			for (int c=0; c<T; c++) {
				if (sl[c][prex]) bit[c].bit_add(i,-1);
				if (sl[c][x]) bit[c].bit_add(i,1);
			}
		} else {
			int l, r, k;
			cin >> l >> r >> k;
			int ok = 1;
			for (int i=0; i<T; i++) {
				if ((bit[i].bit_ps(r)-bit[i].bit_ps(l-1))%k) {
					ok = 0;
					break;
				}
			}
			cout << (ok?"YES\n":"NO\n");
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