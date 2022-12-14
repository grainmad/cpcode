#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;
ll BIT1[N];
ll BIT2[N];

// ll xBIT[N];

void bit_add(int x, ll val, ll* B) {
    for (int i=x; i<N; i+=i&-i) {
        B[i] += val;       
    }
}

ll bit_ps(int x, ll* B) {
    ll rt = 0;
    for (int i=x; i>0; i-=i&-i) {
        rt += B[i];
    }
    return rt;
}


void sol() {
	int n;
	cin >> n;
	std::vector<int> v(n+1), p(n+1), q(n+1);
	for (int i=1; i<=n; i++) {
		BIT1[i] = BIT2[i] = 0;
		cin >> v[i];
	}
	for (int i=1; i<=n; i++) {
		p[i] = bit_ps(v[i], BIT1);
		bit_add(v[i], 1, BIT1);
	}
	for (int i=n; i>=1; i--) {
		q[i] = bit_ps(v[i], BIT2);
		bit_add(v[i], 1, BIT2);
	}
	for (int i=1; i<=n; i++) {
		cout << p[i] << " ";
	} cout << endl;
	for (int i=1; i<=n; i++) {
		cout << q[i] << " ";
	} cout << endl;
	ll ans = 0;
	// for (int i=2; i<=n-2; i++) {
	// 	for (int j=i+1; j<=n-1; j++) {
	// 		if (v[i] < v[j]) {
	// 			ans += (p[j]-1)*(q[i]);
	// 		} else {
	// 			ans += p[j]*(q[i]-1);
	// 		}	
	// 	}
		
	// }
	cout << ans << endl;
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