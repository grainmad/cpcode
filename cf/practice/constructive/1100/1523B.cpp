//15:25 15:52
#include <bits/stdc++.h>
#define ll long long
#define N 1005
using namespace std;

int n;
int a[N];
int d[6] = {1,2,2,1,2,2};
void sol() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	cout << 3*n << '\n';
	for (int i=0; i<n; i+=2) {
		for (int j=0; j<6; j++) {
			cout << d[j] << " " << 1+i << " " << i+2 << '\n';

		}
	}
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