#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int a=n, b=-1, cnt = 0, d=0;
	for (int i=0; i<n; i++) {
		if (s[i] == '0') continue;
		cnt++;
		a = min(a, i);
		b = max(b, i);
	}
	if (cnt && n-b-1<=k) {
		k-=n-b-1;
		cnt--;
		d+=1;
	}
	if (cnt && a<=k) {
		k-=a;
		cnt--;
		d+=10;
	}
	// cout << cnt << " " << d << endl;
	cout << 11*cnt+d << endl;

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