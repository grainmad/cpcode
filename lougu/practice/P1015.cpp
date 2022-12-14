#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int n;
string m;
std::vector<int> d;

bool ok() {
	int l = 0, r = d.size()-1;
	while (l < r) {
		if (d[l] != d[r]) return false;
		l++; r--;
	}
	return true;
}

void add() {
	std::vector<int> v(d.size(), 0);
	for (int i=0; i<d.size(); i++) {
		v[i] = d[i]+d[d.size()-1-i];
	}
	// for (int i:v) cout << i << " ";
	// 	cout << endl;
	reverse(v.begin(), v.end());
	int nx = 0;
	for (int i=0; i<v.size(); i++) {
		int t = (v[i]+nx)/n;
		v[i] = (v[i]+nx)%n;
		nx = t;
	}
	if (nx) v.push_back(nx);
	reverse(v.begin(), v.end());
	d = v;
}



int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	cin >> n >> m;
	for (char i:m) {
		if ('0' <= i && i<= '9') d.push_back(i-'0');
		if ('a' <= i && i<= 'f') d.push_back(i-'a'+10);
		if ('A' <= i && i<= 'F') d.push_back(i-'A'+10);
	}
	for (int i=0; i<=30; i++) {
		// for (int i:d) cout << i << " ";
		// cout << endl;
		if (ok()) {
			cout << "STEP=" << i << endl;
			return 0;
		}
		add();		

	}
	cout << "Impossible!" << endl;
	return 0;
}