//Dcpy
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node {
	node* nxt[2];
	pair<int, int>v;
	node() :nxt{ 0,0 }, v(-1, -1){}
};
pair<int, int> a[300000];
pair<int, int>dp[300000];
node root;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i != n; ++i)
		cin >> a[i].first, a[i].second = i;
	sort(a, a + n);
	for (int i = 0; i != n; ++i) {
		cout << "a "<< i << " " << a[i].first << " " << a[i].second << endl;
		dp[i] = { 1,-1 };//��ǰ��Ҫ�ҵڼ�������һ����λ���Ƕ���
		node* t = &root;
		for (int j = 29; ~j && t; --j) {
			int dig = a[i].first >> j & 1;
			if (~k >> j & 1) {//k��һλΪ0
				if (t->nxt[!dig])//Ϊ0������û�б��������λ����λ�ش���k
					dp[i] = max(dp[i], t->nxt[!dig]->v);
				t = t->nxt[dig];
			}
			else//Ϊ1�����Ҫ��λ���ܴ��ڵ���
				t = t->nxt[!dig];
		}
		if (t)
			dp[i] = max(dp[i], t->v);
		cout << "dp" << " " << dp[i].first << " " << dp[i].second << endl;
		pair<int, int> v = { dp[i].first + 1,i };
		t = &root;
		//t->v = max(t->v, v);
		for (int j = 29; ~j; --j) {//����ǰ�������ֵ���
			int dig = a[i].first >> j & 1;
			if (!t->nxt[dig])
				t->nxt[dig] = new node;
			t = t->nxt[dig];
			t->v = max(t->v, v);
		}
	}
	int i = max_element(dp, dp + n) - dp;
	if (dp[i].first == 1)
		cout << "-1\n";
	else {
		cout << dp[i].first << '\n';
		for (; ~i; i = dp[i].second)
			cout << a[i].second + 1 << ' ';
		cout << '\n';
	}
}
