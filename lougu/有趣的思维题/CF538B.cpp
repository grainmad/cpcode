#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

string getAns(string& s) {
	int idx=0;
	while (idx < s.size() && s[idx] == '0') idx++;
	string rt;
	for (int i=idx; i<s.size(); i++) {
		if (s[i] != '0') s[i]-=1, rt.push_back('1');
		else rt.push_back('0');
	}
	return rt;
}

void sol() {
	string s;
	cin >> s;
	std::vector<string> v;
	while (1) {
		string t = getAns(s);
		// cout << "S" << s << " t" << t << endl;
		if (t == "") break;
		else v.push_back(t);
	}
	cout << v.size() << endl;
	for (string i:v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// int t;
	// cin >> t;
	// while (t--) {
	// 	sol();
	// }
	sol();
	return 0;
}