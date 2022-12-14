#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

ll a[N];

ll gcd(ll a, ll b) {
	if (a == 0) return b;
	return gcd(b%a, a);
}

struct Frac {
	ll a, b;
	Frac(ll a, ll b): a(a), b(b) {}
	bool operator<(const Frac& o) const{
		return a*o.b < b*o.a;
	}
};

void sol() {
	int n; ll w;
	cin >> n >> w;
	for (int i=0; i<2*n; i++) cin >> a[i];
	sort(a, a+2*n);
	auto p = min(
		Frac(w, 3*n), 
		max(
			min(Frac(a[n], 2), Frac(a[0], 1)), 
			min(Frac(a[n], 1), Frac(a[0], 2))
			)
		);
	p.a*=3*n;
	double a = p.a/gcd(p.a, p.b);
	double b = p.b/gcd(p.a, p.b);
	// printf("%.7lf", a/b);
	cout << fixed << setprecision(7) << a/b;
	// for (int i=0; i<10; i++) {
	// 	a = a%b*10;
	// 	cout << a/b;
	// }
	
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