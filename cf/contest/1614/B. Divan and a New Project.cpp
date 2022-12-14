//B. Divan and a New Project
#include <bits/stdc++.h>
#define MAXN 200005
#define ll long long
using namespace std;

struct Node {
	ll time;
	int id;
	bool operator<(Node& o) {
		return time > o.time;
	}
}build[MAXN];

int pos[MAXN];


int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i=0; i<n; i++) {
			scanf("%lld", &build[i].time);
			build[i].id = i+1;
		}
		sort(build, build+n);
		ll dis = 0;
		for (int i=0; i<n; i++) {
			pos[build[i].id] = i%2?-(i/2+1):(i/2+1);
			dis += (i/2+1)*build[i].time;
		}
		pos[0] = 0;
		printf("%lld\n", 2*dis);
		for (int i=0; i<n; i++) {
			printf("%d ", pos[i]);
		}
		printf("%d\n", pos[n]);
	}
	return 0;
}
