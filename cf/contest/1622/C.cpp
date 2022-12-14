//C
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005

using namespace std;

ll p[MAXN];//p[i] = sum a[0..i-1],   a[i...j] = p[j+1] - p[i]
ll a[MAXN];
int t, n;
ll k;
ll ans, l, r, m1, m2;

ll ac_floor(ll a, ll b) {
	ll t = a/b;
	while (t*b>a) t--;
	return t;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%lld", &n, &k);
		for (int i=0; i<n; i++) {
			scanf("%lld", &a[i]);
		}
		sort(a, a+n);
		for (int i=0; i<n; i++) {
			p[i+1] = p[i]+a[i];
		}
		ll ans = a[0]+n;
		for (int i=0; i<n; i++) {
			ll x = a[0] - ac_floor(k-p[n-i]+a[0], i+1);
			ans = min(ans, i+max(0LL, x));
		}
		printf("%lld\n", ans);
	}
	return 0;
} 
