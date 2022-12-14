//16:24 17:00
#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int n;
int a[N];

void sol() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	if (a[n] == 0) {
		cout << 1;
		for (int i=2; i<=n+1; i++) {
			cout << " " << i;
		}
		cout << '\n';
	} else if (a[1] == 1) {
		cout << n+1;
		for (int i=1; i<=n; i++) {
			cout << " " << i;
		}
		cout << '\n';
	} else {
		int i=n+1;
		for (i=2; i<=n; i++) {
			if (a[i-1] == 0 && a[i] == 1) {
				cout << 1;
				for (int j=2; j<=i-1; j++) cout << " " << j;
				cout << " " << n+1;
				for (int j=i; j<=n; j++) cout << " " << j;
				cout << '\n';
				break;
			}
		}
		if (n+1 == i) cout << "-1\n";
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