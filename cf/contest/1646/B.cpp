#include <bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;

ll a[N];
int n;

void sol() {
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	ll ls = a[0]+a[1], rs = a[n-1];
	int l = 1, r = n-1;
	bool flag = false;
	while (1) {
		if (ls<rs) {
			flag = true;
			break;
		}
		l++, r--;
		if (l<r) ls+=a[l], rs+=a[r];
		else break;
	}
	cout << (flag?"YES":"NO") << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}