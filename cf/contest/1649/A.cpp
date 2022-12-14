#include <bits/stdc++.h>
#define ll long long
#define N 105
using namespace std;

int n;
int a[N];

void sol() {
	cin >> n; 
	for (int i=0; i<n; i++) cin >> a[i];
	int l = 0, r = n-1;
	while (l<n && a[l] != 0) l++;
	while (r>=0 && a[r] != 0) r--;
	if (l>r) cout << "0\n";
	else cout << r-l+2 << "\n";
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