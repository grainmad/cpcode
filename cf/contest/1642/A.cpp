#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;


void sol() {
	std::vector<pair<ll, ll>> v(3);
	for (int i=0; i<3; i++) {
		cin >> v[i].second >> v[i].first;
	}
	sort(v.begin(), v.end());
	if (v[2].first == v[1].first && v[0].first < v[2].first) {
		cout << abs(v[2].second-v[1].second) << '\n';
	} else {
		cout << "0\n";
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