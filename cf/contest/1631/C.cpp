#include <bits/stdc++.h>
#define MAXN 200005
#define ll long long
using namespace std;


int num[MAXN];

void sol() {
	int n, k;
	cin >> n >> k;

	if (k == n-1 && n == 4) {
		//除了n=4的情况
		cout << "-1\n";
		return ;
	}
	for (int i=0; i<n; i++) {
		num[i] = i;
	}
	if (n-1 == k) {
		swap(num[0], num[n-2]);//num[0]&num[n-1] = n-2
		swap(num[3], num[n-2]);//num[3]&num[n-4] = 0 , num[1]&num[n-2] = 1
	} else {
		swap(num[0], num[k]);
	}
	for (int i=0; i<n/2; i++) cout << num[i] << " " << num[n-i-1] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		sol();
	}
	return 0;
}