//C
#include <bits/stdc++.h>
using namespace std;

int st[30];

void sol() {
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	memset(st, 0, sizeof(st));
	for (int i=0; i<s.size(); i++) {
		st[s[i]-'a']++;
	} 
	int a=0, b=0;
	for (int i=0; i<26; i++) {
		a += st[i]/2;
		b += st[i]%2;
	}
	if (a%k*2+b>=k) cout << a/k*2+1 << endl;
	else cout << a/k*2 << endl;
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
