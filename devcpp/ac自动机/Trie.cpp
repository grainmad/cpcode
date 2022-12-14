// Trie  
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1000005
#define SIGMA 26
//����СдӢ����ĸ 
using namespace std;
namespace Trie {
	int tr[MAXN][SIGMA];//����洢Trie���ڵ�,�±���ָ������
	int val[MAXN];//����ǰ�ڵ㲻��һ��ģʽ���Ľ�β��Ϊ0 
	int sz;//Trie�е�ǰ�ڵ���� 
	Trie() {
		memset(tr, 0, sizeof(tr));
		memset(val, 0, sizeof(val));
		sz = 1;
	} 
	//����
	void insert(char* s) {
		int len = strlen(s), u = 0;
		for (int i=0; i<len; i++) {
			if (tr[u][s[i]-'a'] == 0) {//�������¿���һ���ڵ� 
				tr[u][s[i]-'a'] = sz;
				sz++;
			}
			u = tr[u][s[i]-'a'];
		}
		val[u] = 1;
	}
	//��ѯs�Ƿ����
	bool query(char* s) {
		int len = strlen(s), u = 0;
		for (int i=0; i<len; i++) {
			if (tr[u][s[i]-'a'] == 0) return false;
			u = tr[u][s[i]-'a'];
		}
		return val[u];
	} 
};

char txt[100];
char pat[5][100] = {"i", "she", "his", "hers", "he"};


int main() {
	Trie::Trie();
	for (int i=0; i<5; i++) {
		Trie::insert(pat[i]);
	}
	while (1) {
		cin >> txt;
		cout << Trie::query(txt) << endl;
	}
	return 0;
} 
