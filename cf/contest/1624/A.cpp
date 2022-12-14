//A
#include <bits/stdc++.h>

using namespace std;

int num[55];
int n;

void sol() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> num[i];
	}
	sort(num, num+n);
	int opt = 0;
	for (int i=n-2; i>=0; i--) {
		opt += num[i+1]-num[i];
	}	
	cout << opt << endl;
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
