#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000006


bool in[MAXN];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	ios::sync_with_stdio(false);
		cin.tie(0);
	int n, x; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x; 
		in[x] = true;
	}
	int ans = 0;
	for (int i=1; i<MAXN; i++) {
		int t = 0;
		for (int j=i; j<MAXN; j+=i) {
			if (in[j]) {
					t = gcd(t, j);
			}
		}
		if (t == i) ans++;
	}
	cout << ans - n << endl;
	return 0;
}

