#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int a[N];

void sol() {
	int n, k;
	cin >> n >> k;
	for (int i=1; i<=2*n; i++) {
		a[i] = i;
	}
	for (int i=1; i<=2*k; i+=2) {
		swap(a[i], a[i+1]);
	}
	for (int i=1; i<=2*n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// int t;
	// cin >> t;
	// while (t--) {
	// 	sol();
	// }
	sol();
	return 0;
}