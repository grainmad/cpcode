#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;


void sol() {
	string a, b;
	cin >> a;
	cin >> b;
	for (int i=0; i<a.size(); i+=2) {
		if (a[i] == b[0]) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";

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