#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

ll a[N];
int h[N];


void sol() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		for (int j=0; ;j++) {
			if (a[i] >> j == 0) {
				h[i] = j;
				break;
			}
		}
	}
	for (int i=2; i<n; i++) {
		if (h[i-2] == h[i-1] && h[i-1] == h[i]) {
			cout << 1 << endl;
			return ;
		}
	}
	int ans = N;
	for (int i=1; i<n; i++) {
		int sl = 0;
		for (int j=i-1; j>=0; j--) {
			sl^=a[j];
			int sr = 0;
			for (int k=i; k<n; k++) {
				sr^=a[k];
				if (sl>sr) {
					ans = min(ans, k-j-1);
				}	
			}
			
		}
	}
	if (ans == N) cout << -1 << endl;
	else cout << ans << endl;

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