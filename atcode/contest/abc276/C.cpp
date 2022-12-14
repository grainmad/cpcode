#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];

// void sol() {
// 	int n;
// 	cin >> n;
// 	for (int i=0; i<n; i++) cin >> a[i];
// 	prev_permutation(a, a+n); 
// 	for (int i=0; i<n; i++) {
// 		cout << a[i] << " ";
// 	}
// 	cout << endl;
// }


void sol() {
	int n; cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	int p = n-2;
	while (p>=0 && a[p]<=a[p+1]) p--;
	if (p != -1) {
		int q = n-1;
		while (a[p]<=a[q]) q--;
		swap(a[p], a[q]);
	}
	reverse(a+p+1, a+n);
	for (int i=0; i<n; i++) cout << a[i] << " "; cout << endl;
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