#include <bits/stdc++.h>
#define ll long long
#define MAXN 300005
using namespace std;

int n, q;
ll MOD;
ll A[MAXN];
ll fb[MAXN];


void sol() {
	cin >> n >> q >> MOD;
	fb[0] = 0, fb[1] = 1;
	for (int i=2; i<MAXN; i++) fb[i] = (fb[i-1]+fb[i-2])%MOD;
	for (int i=1; i<=n; i++) cin >> A[i];
	ll t;
	for (int i=1; i<=n; i++) {
		cin >> t;
		A[i] = (A[i]-t+MOD)%MOD;
	}
	for (int i=n; i>=3; i--) {
		A[i] = (A[i]-A[i-1]-A[i-2]+2*MOD)%MOD;
	}
	A[2] = (A[2]-A[1]+MOD)%MOD;
	int zcnt = 0;
	for (int i=1; i<=n; i++) {
		if (A[i] == 0) zcnt++;
	}
	// for (int i=1; i<=n; i++) {
	// 	cout << A[i] << " ";
	// }cout << endl;
	string c;
	int l, r;
	for (int i=0; i<q; i++) {
		cin >> c >> l >> r;
		int w = 1;
		if (c== "B") w = -1; 
		if (A[l] == 0 && (A[l]+w)%MOD != 0) zcnt--;
		if (A[l] != 0 && (A[l]+w)%MOD == 0) zcnt++;
		if (r+1<=n && A[r+1] == 0 && (A[r+1]-w*fb[r-l+2]+MOD)%MOD != 0) zcnt--;
		if (r+1<=n && A[r+1] != 0 && (A[r+1]-w*fb[r-l+2]+MOD)%MOD == 0) zcnt++;
		if (r+2<=n && A[r+2] == 0 && (A[r+2]-w*fb[r-l+1]+MOD)%MOD != 0) zcnt--;
		if (r+2<=n && A[r+2] != 0 && (A[r+2]-w*fb[r-l+1]+MOD)%MOD == 0) zcnt++;
		A[l] = (A[l]+w)%MOD;
		A[r+1] = (A[r+1]-w*fb[r-l+2]+MOD)%MOD;
		A[r+2] = (A[r+2]-w*fb[r-l+1]+MOD)%MOD;
		cout <<(zcnt == n ? "YES" : "NO") << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	sol();
	return 0;
}