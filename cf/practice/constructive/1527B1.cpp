//14:12 15:09
#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int n;
string s;

void sol() {
	cin >> n >> s;
	int cnt = 0;
	for (int i=0; i<n; i++) {
		if (s[i] == '0') cnt++;
	}
	cout << (cnt%2&&cnt!=1 ? "ALICE\n":"BOB\n");

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