#include <bits/stdc++.h>
#define ll long long
#define N 1000
using namespace std;


void sol() {
	int n, t, a = 0 ;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> t;
		a |= t;
	}
	cout << a << '\n';

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