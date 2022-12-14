#include <bits/stdc++.h>
#define MAXN 100005
using namespace std; 

int num[MAXN];
int num2[MAXN];
int n, x, t;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &x);
		for (int i=0; i<n; i++) {
			scanf("%d", &num[i]);
			num2[i] = num[i];
		}
		sort(num2, num2+n);
		if (n>=2*x) printf("YES\n");
		else {
			bool flag = true;
			for (int i=n-x; i<x; i++) {
				if (num2[i] != num[i]) {
					flag = false;
					break;
				}
			}
			if (flag) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0; 
}

