#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

ll num[N];
int n;

ll getans(ll mx) {
	ll a=0, b=0;
	for (int i=0; i<n; i++) {
		a += (mx-num[i])/2;
		b += (mx-num[i])%2;
	}
	if (b > a) {
		return 2*b-1;
	} else {
		ll d = (a-b)/3;
		a -=d;
		b +=2*d;
		ll m = max(a*2, b*2-1);
		if (a > b) {
			a--;
			b+=2;
			m = min(m, max(a*2, b*2-1));
		}
		return m;
	}
}

void sol() {
	cin >> n;
	for (int i=0; i<n; i++) cin >> num[i];
	ll mx = *max_element(num, num+n);
	cout << min(getans(mx), getans(mx+1)) << endl;
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