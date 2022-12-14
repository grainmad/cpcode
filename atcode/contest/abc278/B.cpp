#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998224353
using namespace std;

int to_t(string s) {
	int a = stoi(s.substr(0, 2));
	int b = stoi(s.substr(3));
	return a*60+b;
}

string to_s(int x) {
	auto a = to_string(x/60);
	if (a.size() == 1) a = "0"+a;
	auto b = to_string(x%60);
	if (b.size() == 1) b = "0"+b;
	return a+" "+b;
}

bool iscf(string s) {
	swap(s[1], s[3]);
	int a = stoi(s.substr(0, 2));
	int b = stoi(s.substr(3));
	if (0<=a && a<24 && 0<=b && b<60) return true;
	return false;
}

void sol() {
	int a, b;
	cin >> a >> b;
	auto s = to_s(a*60+b);
	while (!iscf(s)) {
		int p = (to_t(s)+1)%1440;
		s = to_s(p);
	}
	cout << s << endl;

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