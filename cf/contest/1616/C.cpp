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
				int t = 0;//���㹫�ȵ�Ԫ�ظ��� 
				for (int k=0; k<n; k++) {
					//(num[i]-num[k])/(i-k) == (num[j]-num[k])/(j-k) 
					if (k == i || k == j || (num[i]-num[k])*(j-k) == (num[j]-num[k])*(i-k)) t++;
				}
				ans = min(ans, n-t);//ά����С�Ĳ����㹫�ȵĸ��� 
			}
		}
		cout << (ans == MAXN ? 0 : ans) << endl;
	}
	return 0;
}
