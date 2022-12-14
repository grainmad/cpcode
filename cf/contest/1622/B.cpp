//b
#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int p[MAXN];
int ans[MAXN];

struct Node {
	int val;
	int idx;
	bool operator<(Node& o) {
		return val < o.val;
	}
};
vector<Node> a, b;

char s[MAXN];

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		memset(p, 0, sizeof(p));
		memset(ans, 0, sizeof(ans));
		a.clear();
		b.clear();
		scanf("%d", &n);
		for (int i=0; i<n; i++) {
			scanf("%d", &p[i]);
		}
		scanf("%s", s);
		int t = 1;
		for (int i=0; i<n; i++) {
			if (s[i] == '0') {
				a.push_back({p[i], t++});
			}
			if (s[i] == '1') {
				b.push_back({p[i], t++});
			}
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		t = 1;
		for (int i=0; i<a.size(); i++) {
			ans[a[i].idx] = t++;
		}
		for (int i=0; i<b.size(); i++) {
			ans[b[i].idx] = t++;
		}
		for (int i=1; i<n; i++) {
			printf("%d ", ans[i]);
		} 
		printf("%d\n", ans[n]);
	}
	return 0;
}
