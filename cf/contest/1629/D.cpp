#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

bool pld(string& a) {
	int l = 0, r = a.size()-1;
	while (l < r) {
		if (a[l] != a[r]) return false;
		l++; r--;
	}
	return true;
}

void sol() {
	unordered_set<string> st;
	stack<string> bc;
	bool ok = false;
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		string x;
		cin >> x;
		string y(x.rbegin(), x.rend());
		bc.push(y);
		if (x == y) ok = true;
		if (st.count(y)) ok = true;
		if (y.size() == 3 && st.count(y.substr(0,2))) ok = true;
		st.insert(x);
	}
	st.clear();
	while (!bc.empty()) {
		string x = bc.top(); bc.pop();
		string y(x.rbegin(), x.rend());
		if (x == y) ok = true;
		if (st.count(y)) ok = true;
		if (y.size() == 3 && st.count(y.substr(0,2))) ok = true;
		st.insert(x);
	}
	cout << (ok?"YES\n":"NO\n");
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