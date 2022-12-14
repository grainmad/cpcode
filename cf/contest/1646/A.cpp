#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;


void sol() {
	ll n, s;
	cin >> n >> s;
	cout << (s/(n*n)) << '\n';
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