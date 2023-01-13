//17:23 17:58
#include <bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;

std::vector<int> v[N];
int ans[N];
int n, k;

void sol() {
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		v[i].clear();
		ans[i] = 0;
	}
	int t = 0;
	for (int i=1; i<=n; i++) {
		cin >> t;
		v[t].push_back(i);
	}
	std::vector<int> st;
	for (int i=1; i<=n; i++) {
		// cout << v[i].size() << endl;
		if (v[i].size()>=k) {
			for (int j=1; j<=k; j++) {
				ans[v[i][j-1]] = j;
			}
		} else {
			for (int j:v[i]) st.push_back(j);
		}
	}
	int sz = st.size()/k*k;
	for (int i=0; i<sz; i++) {
		ans[st[i]] = i%k+1;
	}
	cout << ans[1];
	for (int i=2; i<=n; i++) {
		cout << ' ' << ans[i];
	}
	cout << '\n';
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