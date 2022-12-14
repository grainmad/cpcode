#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

/*

将剩余数字分为a0, a1, a2三部分，
最多三次查询可以减少1/3规模
最后剩余两个可以直接猜。
100000 * (2/3)^x = 2
math.log(2/100000, 2/3) = 26.684856644986407

27*3 = 81
最多81次

a0 a1
y  y     

两者不可能同时为真，也不可能同时为假
a0=y为假则a1=y为真，必在a1
a0=y为真则a1=y为假，必在a0
必在a0+a1

a0 a1
y  n     
不可能同时为假
a0=y真且a1=n假不可能存在
a0=y真且a1=n真，必在a0
a0=y假且a1=n真，必在a2
必在a0+a2

a0 a0
n  n
不可能同时为假，也不可能一真一假，只可能都为真,不在a0
必在a1+a2

a0 a1
n  y
回到第一二两种情况
*/


bool ask(vector<int>& v) {
	cout << "? " << v.size();
	for (int i:v) {
		cout << " " << i;
	}
	cout << endl;
	string s;
	cin >> s;
	return s=="YES";
}

void merge(vector<int>& a, vector<int>& b, vector<int>& to) {
	to.clear();
	for (int i:a) to.push_back(i);
	for (int i:b) to.push_back(i);
}

void sol() {
	int n; cin >> n;
	std::vector<int> v(n);
	for (int i=0; i<n; i++) v[i] = i+1;
	while (true) {
		vector<int> a[3];
		for (int i=0; i<v.size(); i++) {
			a[i%3].push_back(v[i]);
		}
		if (ask(a[0])) {
			if (ask(a[1])) {
				merge(a[0], a[1], v);
			} else {
				merge(a[0], a[2], v);
			}
		} else {
			if (ask(a[0])) {
				if (ask(a[1])) {
					merge(a[0], a[1], v);
				} else {
					merge(a[0], a[2], v);
				}
			} else {
				merge(a[1], a[2], v);
			}
		}
		if (v.size()<=2) {
			cout << "! " << v[0] << endl;
			string s;
			cin >> s;
			if (s == ":(") {
				cout << "! " << v[1] << endl;
				cin >> s;
			}
			break;
		}
	}
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