//10:00 22:25
#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;


void sol() {
	int n;
	cin >> n;
	for (int i=0; i<31; i++) {
		if (n-1>>i == 1) {
			int s = 1<<i;
			std::vector<int> v;
			for (int j=s+1; j<n; j++) {
				v.push_back(j);
			}
			v.push_back(s);
			for (int j=0; j<s; j++) {
				v.push_back(j);
			}
			cout << v[0];
			for (int j=1; j<v.size(); j++) {
				cout << " " << v[j];
			}
			cout << endl;
			return ;
		}
	}
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