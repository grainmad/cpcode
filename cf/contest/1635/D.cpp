#include <bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;

int MOD = 1e9+7;

int n, p;
ll a[N];

void sol() {
	cin >> n >> p;
	ll ans = 0;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		ll t = a[i]+1, pos;
		for (pos=0; (1LL<<pos)<t; pos++);
		if (p-pos>0) ans = (ans+p-pos)%MOD;
		t = a[i];
		for (pos=0; (1LL<<pos)<=t; pos++);
		if (pos<=p) ans = (ans+1)%MOD;
		if ((p-pos)/2>0) ans =  (ans+(p-pos)/2)%MOD;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	sol();
}