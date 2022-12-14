#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	cin >> n;
	string u, v;
	cin >> u >> v;
	int cnta=0, cntb=0;
	int ans1 = 0, ans2 = 0;
	for (int i=0; i<n; i++) {
		if (u[i] == 'a') cnta++;
		else cntb++;
		if (v[i] == 'a') cnta++;
		else cntb++;
		if (u[i] == 'a' && v[i] == 'b') ans1++;
		if (u[i] == 'b' && v[i] == 'a') ans2++;
	}
	if (cnta%2 || cntb%2) {
		cout << "-1\n";
		return;
	}
	cout << (ans1+1)/2+(ans2+1)/2 << "\n"; 
	int p = -1;
	for (int i=0; i<n; i++) {
		if (u[i] == 'a' && v[i] == 'b') {
			if (p == -1) p = i;
			else {
				swap(u[p], v[i]);
				cout << p+1 << " " << i+1 << "\n";
				p = -1;
			}
		}
	}
	p = -1;
	for (int i=0; i<n; i++) {
		if (u[i] == 'b' && v[i] == 'a') {
			if (p == -1) p = i;
			else {
				swap(u[p], v[i]);
				cout << p+1 << " " << i+1 << "\n";
				p = -1;
			}
		}
	}
	p = -1;
	for (int i=0; i<n; i++) {
		if (u[i] != v[i]) {
			if (p == -1) p = i;
			else {
				swap(u[i], v[i]);
				swap(u[p], v[i]);
				cout << i+1 << " " << i+1 << "\n";
				cout << p+1 << " " << i+1 << "\n";
				p = -1;
			}
		}
	}
	// cout << u << " " << v << endl;
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