//C
#include <bits/stdc++.h>
#define MAXN 100
using namespace std;
int num[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> num[i];
		}
		int ans = MAXN;
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				int t = 0;//满足公比的元素个数 
				for (int k=0; k<n; k++) {
					//(num[i]-num[k])/(i-k) == (num[j]-num[k])/(j-k) 
					if (k == i || k == j || (num[i]-num[k])*(j-k) == (num[j]-num[k])*(i-k)) t++;
				}
				ans = min(ans, n-t);//维护最小的不满足公比的个数 
			}
		}
		cout << (ans == MAXN ? 0 : ans) << endl;
	}
	return 0;
}
