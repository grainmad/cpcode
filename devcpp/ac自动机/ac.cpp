#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring> 
#define MAXN 1000005
#define SIGMA 26
using namespace std; 
/*
1. �����ֵ��� 
2. ����failָ����ֵ�ͼ
*/


namespace Ac {
	int tr[MAXN][SIGMA];
	int val[MAXN];//�ؼ��ֽڵ� val[i] i�Žڵ��Ǳ��Ϊval[i]��ģʽ������1��ʼ 
	int fail[MAXN];//ָ����ĺ�׺����ǰ׺����ǰ׺
	int last[MAXN];//��fail����ָ�����Լ�����Ĺؼ��ֽڵ� 
	int cnt[MAXN]; //cnt[i] ���Ϊi��ģʽ�����ֵĴ����� 
	int sz;//�ڵ���� 
	int id;//Ϊ�������ģʽ�������id 
	Ac() {
		memset(tr, 0, sizeof(tr));
		memset(val, 0, sizeof(val));
		memset(fail, 0, sizeof(fail));
		sz = 1;
		id = 1;
	}
	//����
	void insert(char* s) {
		int len = strlen(s), u = 0;
		for (int i=0; i<len; i++) {
			if (tr[u][s[i]-'a'] == 0) {
				tr[u][s[i]-'a'] = sz++;
			}
			u = tr[u][s[i]-'a'];
		}
		val[u] = id++;
	} 
	//����failָ����ֵ�ͼ �Ż����ڽ���fail���ٽ���last 
	void build() {
		queue<int> que;
		for (int i=0; i<SIGMA; i++) {
			if (tr[0][i]) que.push(tr[0][i]);
		}
		while (!que.empty()) {
			int u = que.front(); que.pop();
			for (int i=0; i<SIGMA; i++) {
				if (tr[u][i]) {//���� 
					fail[tr[u][i]] = tr[fail[u]][i];
					last[tr[u][i]] = val[fail[tr[u][i]]]?fail[tr[u][i]]:last[fail[tr[u][i]]];//�Ż� 
					que.push(tr[u][i]);
				} else {
					tr[u][i] = tr[fail[u]][i];
				}
			}
		}
	} 
	//��ѯ, ÿ���ڵ㶼Ҫ������fialָ��ֱ�����ڵ㣬 �ڼ�����е��ʽڵ� 
	void query(char* s) {
		int u = 0;
		for (int i=0, len=strlen(s); i<len; i++) {
			for (int j=tr[u][s[i]-'a']; j; j=fail[j]) {
				if (val[j] != 0) {//j�ǵ��ʽڵ� 
					cnt[val[j]]++;
					printf("���Ϊ%d��ģʽ�����һ���ַ��������ı����±�%dλ��\n", val[j], i); 
				}
			}
			u = tr[u][s[i]-'a'];
		}
	} 
	//�Ż���ѯ 
	void queryWithLast(char* s) {
		int u = 0;
		for (int i=0, len=strlen(s); i<len; i++) {
			for (int j=tr[u][s[i]-'a']; j; j=last[j]) {
				if (val[j] != 0) {//j�ǵ��ʽڵ� 
					cnt[val[j]]++;
					printf("���Ϊ%d��ģʽ�����һ���ַ��������ı����±�%dλ��\n", val[j], i); 
				}
			}
			u = tr[u][s[i]-'a'];
		}
	} 
	//��ӡÿ���ַ������ִ���
	void print() {
		printf("ÿ��ģʽ�����ֵĴ���\n"); 
		for (int i=1; i<id; i++) {
			printf("%d %d\n", i, cnt[i]);
		}
	} 
	//debug
	void debug() {
		for (int i=0; i<sz; i++) {
			printf("fail[%d]=%d\n", i, fail[i]);
		}
		for (int i=0; i<sz; i++) {
			printf("last[%d]=%d\n", i, last[i]);
		}
	} 
}

char txt[100];
//char pat[5][100] = {"i", "she", "his", "hers", "he"};
char pat[8][100] = {
"abc",
"aabc",
"aaabc",
"aaaabc",
"aaaaabc",
"ab",
"aaab",
"aaaaab"
};

int main() {
	Ac::Ac();
	for (int i=0; i<8; i++) {
		Ac::insert(pat[i]);
		cout << i+1 << " " << pat[i] << endl;
	}
	Ac::build();
	while (1) {
		cin >> txt;
		Ac::queryWithLast(txt);
		Ac::print();
		Ac::debug();
		memset(Ac::cnt, 0, sizeof(Ac::cnt));
	}
	return 0;
}
