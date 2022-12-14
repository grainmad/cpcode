#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

void sol() {
	int n, t;
	cin >> n;
	std::vector<int> o, e;
	for (int i=0; i<n; i++) {
		cin >> t;
		if (t%2) o.push_back(t);
		else e.push_back(t);
	}
	bool flag = true;
	for (int i=1; i<o.size(); i++) if (o[i-1]>o[i]) flag = false;
	for (int i=1; i<e.size(); i++) if (e[i-1]>e[i]) flag = false;
	cout << (flag?"YES":"NO") << "\n";
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