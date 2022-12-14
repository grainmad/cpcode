#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int n;
int a[N];

void sol() {
	cin >> n;
	unordered_map<int,int> mp;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		mp[--a[i]] = i;
	}
	std::vector<int> v;
	for (int i=n-1; i>=0; i--) {
		// for (int k=0; k<n; k++) {
		// 	cout << mp[k] << " ";
		// } cout << endl;
		int mv = (mp[i]-i+i+1)%(i+1);
		v.push_back(mv);
		for (int j=0; j<=i; j++) {
			mp[j] = (mp[j]-mv+i+1)%(i+1);
		}
		
	}
	for (int i=n-1; i>=0; i--) cout << v[i] << " ";
	cout << endl;
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