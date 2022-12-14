//B
#include <bits/stdc++.h>
#define MAXN 150005
using namespace std;

int num[MAXN];
int pre[MAXN];
void sol() {
    memset(pre, -1, sizeof(pre));
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> num[i];
    }
    int ans = -1;
    for (int i=0; i<n; i++) {
        if (pre[num[i]] != -1) {
            ans = max(ans, pre[num[i]]+n-i);
        }
        pre[num[i]] = i;
    }
    cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>> t;
	while (t--) {
		sol();
	} 
	return 0;
}
