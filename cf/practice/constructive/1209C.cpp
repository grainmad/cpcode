#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	int n;
	string s;
	cin >> n >> s;
	for (char i='0'; i<='9'; i++) {
		string a, b, v(n, '#');
		int l=0, r=n-1;
		for (int j=0; j<n; j++) {
			if (s[j]<i) a.push_back(s[j]), v[j] = '1', l=max(l, j);
			else if (s[j]>i) b.push_back(s[j]), v[j] = '2', r=min(r,j);
		}
		if ((a.empty() || is_sorted(a.begin(), a.end())) 
			&& (b.empty() || is_sorted(b.begin(), b.end()))) {
			for (int i=l; i<n; i++) {
				if (v[i] == '#') v[i] = '1';
			}
			for (int i=r; i>=0; i--) {
				if (v[i] == '#') v[i] = '2';
			}
			if (count(v.begin(), v.end(), '#') == 0) {
				cout << v << "\n";
				return ;
			}
		}
	}
	cout << "-\n";
	// vector<int> st;
	// char mn = '9';
	// for (int i=0; i<n; i++) {
	// 	while (!st.empty() && s[st.back()] > s[i]) {
	// 		v[st.back()] = '2';
	// 		mn = min(mn, s[st.back()]);
	// 		st.pop_back();
	// 	}
	// 	v[i] = '1';
	// 	st.push_back(i);
	// }
	// // for (int i:st) cout << i << " ";
	// // cout << " " << mn << endl;
	// while (!st.empty() && s[st.back()] > mn) {
	// 	v[st.back()] = '2';
	// 	st.pop_back();
	// }
	// int p = -1;
	// for (int i=0; i<n; i++) {
	// 	if (v[i] == '2') {
	// 		if (p == -1) p = i;
	// 		else if (s[i]>=s[p]) {
	// 			p = i;
	// 		} else {
	// 			cout << "-\n";
	// 			return ;
	// 		}
	// 	}
	// }
	// cout << v << "\n";
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