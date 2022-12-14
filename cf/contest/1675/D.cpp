#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];

void sol() {
	int n;
	cin >> n;
	std::vector<bool> v(n+1, false);
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		v[a[i]] = true;
	}
	if (n == 1) {
		cout << "1\n1\n1\n\n"<< endl;
		return ;
	}
	int cnt = 0;
	for (int i=1; i<=n; i++) {
		if (!v[i]) cnt++;
	}
	cout << cnt << endl;
	bool flag = true;
	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			std::vector<int> st;
			int t = i;
			while (t != a[t]) { 
				st.push_back(t);
				int u = a[t];
				t = a[t];
			}
			if (flag) {
				st.push_back(t);
				flag = false;
			}
			cout << st.size() << endl;
			// for (int j:st) {
			// 	cout << j << " ";
			// 	a[j] = j;
			// }
			int sz = st.size();
			for (int j=sz-1; j>=0; j--) {
				cout << st[j] << " ";
				a[st[j]] = st[j];
			}
			cout << endl;
		}
	}
	cout << endl;
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