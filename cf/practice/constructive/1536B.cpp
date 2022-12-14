//13:08 14:11
#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int st[3][27000];
string s;

void sol() {
	int n; 
	cin >> n >> s;
	for (int i=0, sz = 1; i<3; i++) {
		sz *= 26;
		for (int j=0; j<sz; j++) {
			st[i][j] = 0;
		}
	}
	for (int i=0; i<n; i++) {
		int t = 0;
		for (int j=0; j<3 && i+j<n; j++) {
			t*=26;
			t+=s[i+j]-'a';
			st[j][t] = 1;
		}
	}
	// for (int i=0; i<3; i++) {
	// 	for (int j=0; j<n; j++) {
	// 		cout << i << "," << j << "=" << st[i][j] << " ";
	// 	} cout << endl;
	// }
	for (int i=0, sz=1; i<3; i++) {
		sz *= 26;
		for (int j=0; j<sz; j++) {
			if (st[i][j] == 0) {
				for (int k=0; k<=i; k++) {
					sz = sz/26;
					char t = ('a'+j/sz);
					cout << t;
					j %= sz;
				}
				cout << '\n';
				return ;
			}
		}
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