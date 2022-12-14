//A - Keywords Search HDU - 2222 
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define N 1000005
#define MAXN 500005
#define SIGMA 26
using namespace std;


int tr[MAXN][SIGMA];
int fail[MAXN];
int last[MAXN];
int val[MAXN];//相同pattern出现次数
int sz = 1;

void tr_insert(char* str) {
	int len = strlen(str), u = 0;
	for (int i=0; i<len; i++) {
		if (tr[u][str[i]-'a'] == 0) {
			tr[u][str[i]-'a'] = sz++;
		}
		u = tr[u][str[i]-'a'];
	}
	val[u]++;//出现次数 
} 

void tr_build() {
	queue<int> que;
	for (int i=0; i<SIGMA; i++) {
		if (tr[0][i]) que.push(tr[0][i]);
	}
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (int i=0; i<SIGMA; i++) {
			if (tr[u][i]) {
				fail[tr[u][i]] = tr[fail[u]][i];
				last[tr[u][i]] = val[fail[tr[u][i]]] ? fail[tr[u][i]]:last[fail[tr[u][i]]];
				que.push(tr[u][i]);
			} else {
				tr[u][i] = tr[fail[u]][i];
			}
		}
	}
} 

int tr_query(char* str) {
	int len = strlen(str), u = 0, ans=0;
	for (int i=0; i<len; i++) {
		for (int j=tr[u][str[i]-'a']; j; j=last[j]) {
			if (val[j]) {
				ans += val[j];
				val[j] = 0;
			}
		}
		u = tr[u][str[i]-'a'];
	}
	return ans;
}

char s[N];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(tr, 0, sizeof(tr));
		memset(fail, 0, sizeof(fail));
		memset(last, 0, sizeof(last));
		memset(val, 0, sizeof(val));
		sz = 1;
		int l;
		scanf("%d", &l);
		for (int i=0; i<l; i++) {
			scanf("%s", s);
			tr_insert(s); 
		}
		tr_build();
		scanf("%s", s);
		printf("%d\n", tr_query(s));
	}
	return 0;
}
