#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

// bool ok(string& s) {
// 	int cnt = 0;
// 	for (int i=0; i<s.size(); i++) {
// 		if (s[i] == '#') return false;
// 		if (s[i] == '(') cnt++;
// 		else if (--cnt < 0) return false;
// 	}
// 	return cnt == 0;
// }

void sol() {
	int n; string s;
	cin >> n >> s;
	string a(n, '#'), b(n, '#');
	int cnt1 = count(s.begin(), s.end(), '1');
	if (cnt1%2 || s[0] == '0' || s[n-1] == '0') {
		cout << "NO\n";
		return ;
	}
	int cnt = 0;
	bool flag = true;
	for (int i=0; i<n; i++) {
		if (s[i] == '1') {
			if (cnt*2 < cnt1) a[i] = b[i] = '(';
			else a[i] = b[i] = ')';
			cnt++;
		} else {
			a[i] = flag?'(':')';
			b[i] = flag?')':'(';
			flag = !flag;
		}
	}
	// cout << a << " " << b << endl;
	// if (ok(a) && ok(b)) {
	// 	cout << "YES\n" << a << "\n" << b << "\n";
	// } else {
	// 	cout << "NO\n";
	// }
	cout << "YES\n" << a << "\n" << b << "\n";
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