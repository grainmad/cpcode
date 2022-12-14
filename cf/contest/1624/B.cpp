//B
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void sol() {
	ll a, b, c;
	cin >> a >> b >> c;
	if (2*b-a>0 && (2*b-a)%c == 0 
	|| 2*b-c>0 && (2*b-c)%a == 0 
	|| (c-a)%2==0 && ((c-a)/2+a)>0 && ((c-a)/2+a)%b == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
	return 0;
}
