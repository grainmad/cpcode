#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];
int cnt[N];
void sol() {
	int n; cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	int p = max_element(cnt, cnt+N)-cnt;
	// cout << p << endl;
	cout << n-cnt[p] << endl;
	for (int i=0; i<n; i++) {
		if (a[i] == p) {
			for (int j=i-1; j>=0; j--) {
				if (a[j]>a[j+1]) {
					cout << "2 " << j+1 << " " << j+2 << endl;
				}
				if (a[j]<a[j+1]) {
					cout << "1 " << j+1 << " " << j+2 << endl;
				}
				a[j] = a[j+1];
			}
			for (int j=i; j+1<n; j++) {
				if (a[j]>a[j+1]) {
					cout << "1 " << j+2 << " " << j+1 << endl;
				}
				if (a[j]<a[j+1]) {
					cout << "2 " << j+2 << " " << j+1 << endl;
				}
				a[j+1] = a[j];
			}
			break;
		}
	}

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