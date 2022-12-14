#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998224353
using namespace std;

int n, p;
int a[N];

void sol() {
	cin >> n >> p;
	for (int i=0; i<=n; i++) a[i] = 0;
	set<int> st;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		st.insert(a[i]);
	}
	int pos = -1;
	for (int i=a[n]; i>=0; i--) {
		if (st.count(i) == 0) {
			pos = i;
			break;
		}
	}
	int ans = 0;
	if (pos == -1) { // 0到a[n]完好，考虑a[n]到p-1
		for (int i=p-1; i>=a[n]; i--) {
			if (st.count(i) == 0) {
				ans = i-a[n];
				break;
			}
		}
		cout << ans << "\n";
		return ;
	}
	ans = p-a[n];//a[n]移动到0位置，共p-a[n]步。
	st.insert(0);
	for (int i=n-1; i>=0; i--) {
		if (a[i] != p-1) {
			st.insert(a[i]+1);
			break;
		}
	}
	for (int i=a[n]-1; i>=0; i--) {
		if (st.count(i) == 0) {
			ans += i; // 需要经过0到i,共i+1步
			break;
		}
	}
	cout << ans << endl;
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