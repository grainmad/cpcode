//B. Build the Permutation 
#include <bits/stdc++.h>

using namespace std;

int num[100005];

int main() {
	int t, n, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &a, &b);
		if (abs(a-b)>1 || a+b>n-2) {
			printf("-1\n");
			continue;
		}
		int m = n/2+1;
		for (int e=m, p=0; e<=n; e++, p+=2) {
			num[p] = e;
		}
		for (int e=m-1, p=1; e>=1; e--, p+=2) {
			num[p] = e;
		}
		for (int i=0; i<n; i++) {
			cout << num[i] << " ";
		}
	}
	return 0;
}
