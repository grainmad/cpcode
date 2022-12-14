#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


// int ch[1000];

// void sol() {
// 	ch['S'] = -1;
// 	ch['M'] = 0;
// 	ch['L'] = 1;
// 	string a, b;
// 	cin >> a >> b;
// 	if (a == b) {
// 		cout << "=";
// 	} else if (a.back() == b.back()){
// 		if (a.back() == 'S') {
// 			cout << (a.size()>b.size()?"<":">");
// 		} else {
// 			cout << (a.size()<b.size()?"<":">");
// 		}
// 	} else cout << (ch[a.back()] < ch[b.back()]? "<":">");
// 	cout << "\n";
// }

int f(string& s) {
	int sz = s.size();
	if (s.back() == 'M') return 0;
	if (s.back() == 'S') sz = -sz;
	return sz;
}

void sol() {
	string a, b;
	cin >> a >> b;
	if (f(a) > f(b)) cout << ">\n";
	else if (f(a) < f(b)) cout << "<\n";
	else cout << "=\n";
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