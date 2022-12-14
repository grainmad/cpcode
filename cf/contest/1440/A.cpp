#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;


void sol() {
	int n, c0, c1, h;
	string s;
	cin >> n >> c0 >> c1 >> h;
	cin >> s;
	int cnt0=0, cnt1=0;
	for (char i:s) i=='0'?cnt0++:cnt1++;
	// cout << cnt0 << " " << cnt1 << endl;
	if (c0+h < c1) {
		cout << cnt1*h + c0*(cnt0+cnt1) << endl;
	} else if (c1+h < c0) {
		cout << cnt0*h + c1*(cnt0+cnt1) << endl;
	} else {
		cout << c1*cnt1 + c0*cnt0 << endl;
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
	return 0;
}