#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;


void sol() {
	string s;
	int p, v=0;
	cin >> s;
	cin >> p;
	vector<int> ch(26, 0);
	for (int i=0; i<s.size(); i++) {
		ch[s[i]-'a']++;
		v+=s[i]-'a'+1;
	}
	// cout << v << endl;
	if (v <= p) {
		cout << s << endl;
		return;
	}
	for (int i=25; i>=0; i--) {
		v-=ch[i]*(i+1);
		if (v<=p) {
			ch[i] = (p-v)/(i+1);
			break;
		} else {
			ch[i] = 0;
		}
	}
	// for (int i=0; i<26; i++) {
	// 	cout << ch[i] << " ";
	// } cout << endl;
	string ans;
	for (char i:s) {
		if (ch[i-'a']) {
			ans.push_back(i);
			ch[i-'a']--;
		}
	}
	cout << ans << endl;
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