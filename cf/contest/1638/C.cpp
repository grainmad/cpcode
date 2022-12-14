#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;


int p[N];
int n;


void sol() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> p[i];
	}
	vector<int> st;
	for (int i=0; i<n; i++) {
		if (st.empty()) st.push_back(p[i]);
		else if (st.back()<p[i]) st.push_back(p[i]);
		else {
			int x = st.back();
			while (!st.empty() && st.back()>p[i]) st.pop_back();
			st.push_back(x);
		}
	}
	cout << st.size() << '\n';
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