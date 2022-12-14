#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 1000005
using namespace std;

vector<int> prime;
int nprime[N];

void getprime() {
	int sz = sqrt(N);
	for (int i=2; i<=sz; i++) {
		if (!nprime[i])
		for (int j=i*i; j<N; j+=i) {
			nprime[j] = 1;
		}
	}
	for (int i=2; i<N; i++) {
		if (!nprime[i]) prime.push_back(i);
	}
	// for (int i:prime) cout << i << " ";
}

void sol() {
	ll n; cin >> n;
	getprime();
	int cnt = 0; ll fac=1;
	for (int i:prime) {
		if (n%i == 0) cnt++, fac = i;
		while (n%i == 0) {
			n/=i;
		}
	}
	if (n!=1) cnt++, fac = n;
	cout << (cnt>1?1LL:fac) << "\n";
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