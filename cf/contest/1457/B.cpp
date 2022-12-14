#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int a[N];

void sol() {
	set<int> st;
	int n, k;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		st.insert(a[i]);
	}
	int ans = N;
	for (int i:st) {
		int idx = 0, day = 0;
		while (idx < n) {
			if (a[idx] == i) idx++;
			else {
				day++;
				idx += k;
			}
		}
		ans = min(ans, day);
	}
	cout << ans << endl;
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