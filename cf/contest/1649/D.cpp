#include <bits/stdc++.h>
#define ll long long
#define N 1000005
using namespace std;

int n, c;
int a[N];

void sol() {
	cin >> n >> c;
	set<ll> st;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		st.insert(x);
	}
	std::vector<ll> in(st.begin(), st.end());
	for (int i=1; i<=c; i++) {
		if (st.count(i) == 0) {
			for (ll j:in) {
				if (i*j<=c) {
					auto v = lower_bound(in.begin(), in.end(), i*j);
					if (v != in.end() && *v < (i+1)*j) {
						cout << "No\n";
						return;
					}
				} else break;
			}
		}
	}
	cout << "Yes\n";
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