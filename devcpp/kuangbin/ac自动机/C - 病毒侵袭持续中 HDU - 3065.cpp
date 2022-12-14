//C - ²¡¶¾ÇÖÏ®³ÖÐøÖÐ HDU - 3065
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 50005
#define N 2000005
#define SIGMA 94

using namespace std;

char pat[1005][55];
char txt[N];

int cnt[1005];

int tr[MAXN][SIGMA];
int val[MAXN];
int fail[MAXN];
int last[MAXN];
int sz = 1;

void ac_init() {
	memset(tr[0], 0, sizeof(tr[0]));
	memset(fail, 0, sizeof(fail));
	memset(last, 0, sizeof(last));
	memset(cnt, 0, sizeof(cnt));
	memset(val, 0, sizeof(val));
	sz = 1;
}

void ac_insert(char* s, int id) {
	int len = strlen(s), u = 0;
	for (int i=0; i<len; i++) {
		if (tr[u][s[i]-'!'] == 0) {
			memset(tr[sz], 0, sizeof(tr[sz])); 
			tr[u][s[i]-'!'] = sz++;
		}
		u = tr[u][s[i]-'!'];
	}
	val[u] = id;
}

void ac_build() {
	queue<int> que;
	for (int i=0; i<SIGMA; i++) {
		if (tr[0][i]) {
			que.push(tr[0][i]);
		}
	}
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (int i=0; i<SIGMA; i++) {
			if (tr[u][i]) {
				fail[tr[u][i]] = tr[fail[u]][i];
				last[tr[u][i]] = val[fail[tr[u][i]]]?fail[tr[u][i]]:last[fail[tr[u][i]]];
				que.push(tr[u][i]);
			} else {
				tr[u][i] = tr[fail[u]][i];;
			}
		}
	}
}

void ac_query(char* s) {
	int len = strlen(s), u = 0;
	for (int i=0; i<len; i++) {
		for (int j=tr[u][s[i]-'!']; j; j=last[j]) {
			if (val[j]) {
				cnt[val[j]]++;
			}
		}
		u = tr[u][s[i]-'!'];
	}
}

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		ac_init();
		for (int i=1; i<=n; i++) {
			scanf("%s", pat[i]);
			ac_insert(pat[i], i);
		}
		ac_build();
		scanf("%s", txt);
		ac_query(txt);
		for (int i=1; i<=n; i++) {
			if (cnt[i]) {
				printf("%s: %d\n", pat[i], cnt[i]);
			}
		}	
	}
	return 0;
}
