//B
#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> s;
		int i;
		for (i=1; i<n; i++) {
			if (s[i-1] <= s[i]) break;
		}
		while (i != 1 && i<n) {
			if (s[i-1] >= s[i]) i++;
			else break;
		}
		string a = s.substr(0, i);
		string b = a;
		reverse(b.begin(), b.end());
		cout << a << b << endl;
	}
	
	return 0;
}
