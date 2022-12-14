//B
#include <bits/stdc++.h> 
#define MAXN 100005
#define ll long long
using namespace std;

ll l[MAXN], r[MAXN], c[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++) cin >> l[i] >> r[i] >> c[i];
		cout << c[0] << endl;
		int a=0, b=0;
		for (int i=1; i<n; i++) {
			if (l[i]<l[a]) {
				if (r[b]<r[i]) {
					a = b = i;
					cout << c[i] << endl;
				} else if (r[b] == r[i]) {
					a = b = i;
					cout << c[i] << endl;
				} else if (r[b]>r[i]) {
					a = i;
					cout << c[i]+c[b] << endl;
				}
			} else if (l[i] == l[a]) {
				if (r[b]<r[i]) {
					a = b = i;
					cout << c[i] << endl;
				} else if (r[b] == r[i]) {
					if (a == b]) {
						if (c[i]<c[a]) {
							a = b = i;
							cout << c[i] << endl;
						} else {
							cout << c[a] << endl;
						}
					} else {
						if (c[a]+c[b]>c[i]) {
							a = b = i;
							cout << c[i] << endl;
						} else {
							cout << c[a]+c[b] << endl;
						}
					}
				} else if (r[b]>r[i]) {
					if (a == b) {
						cout << c[a] << endl;
					} else {
						if (c[a]>c[i]) {
							a = i;
						}
						cout << c[a]+c[b] << endl;
					}
				}
			} else if (l[i]>l[a]) {
				if (r[b]<r[i]) {
					b = i;
					cout << c[i]+c[a] << endl;
				} else if (r[b] == r[i]) {
					if (a == b) {
						cout << c[a] << endl;
					} else {
						if (c[b]>c[i]) {
							b = i;
						}
						cout << c[a]+c[b] << endl;
					}
				} else if (r[b]>r[i]) {
					if (a == b) cout << c[a] << endl; 
					else cout << c[a]+c[b] << endl;
				}
			}
		}
	}
	return 0;
}
