#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int a[MAXN];
int cnt[MAXN];
int pre[MAXN];


void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cnt[i] = pre[i] = 0;
 	}
	for (int i=0; i<n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	std::vector<int> ans;
	int u = 0;
	for (int i=0; i<n; i++) {
		cnt[a[i]]--;
		pre[a[i]]++;
		if (u == a[i]) {
			while (pre[u]) u++;
		}
		if (cnt[u] == 0) {
			ans.push_back(u);
			// if (u == 0) break;
			while (u != 0) pre[u--] = 0;
		}
	}
	int sz = ans.size();
	cout << sz << endl;
	for (int i=0; i<sz-1; i++) cout << ans[i] << " ";
	cout << ans.back() << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
