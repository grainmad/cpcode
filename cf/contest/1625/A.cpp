//A
#include <bits/stdc++.h>
using namespace std;

int num[105];

void sol() {
	int n, l;
	cin >> n >> l;
	for (int i=0; i<n; i++) {
		cin >> num[i];
	}
	int ans = 0;
	for (int i=0; i<l; i++) {
		int a=0, b=0;
		for (int j=0; j<n; j++) {
			if ((num[j]>>i)&1) a++;
			else b++;
		}
		if (b<a) ans |= (1<<i);
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>> t;
	while (t--) {
		sol();
	} 
	return 0;
}
