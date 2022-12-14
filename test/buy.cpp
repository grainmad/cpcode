#include <bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;



int main() {
	int n;
	cin >> n; //大小
	vector<pair<int,int>> v(n);
	for (int i=0; i<n; i++) cin >> v[i].first;//输入a的价格
	for (int i=0; i<n; i++) cin >> v[i].second;//输入b的价格
	sort(v.begin(), v.end(), [](auto& x, auto& y) {//按照b商店的价格由大到小排序。
		return x.second > y.second;
	});
	double ans = 1e19; // 初始答案无穷大
	int sz = (1<<n);
	for (int i=0; i<sz; i++) {
		/*
		举例
		a 4 3 5 1
		b 7 6 4 2
		若i为10， 二进制 1010
		a中选第二个3 和 第四个4
		b中选第一个2 和 第三个6
		*/
		int a = 0, b = 0, cnta=0, cntb=0;
		for (int j=0; j<n; j++) {
			if (i>>j&1) {
				cnta++;
				a+=v[j].first;
			} else {
				cntb++; //统计第几个0，每第三个0都算作折扣,不加入统计
				if (cntb%3!=0) b += v[j].second;
			}
		}
		ans = min(ans, (cnta>3?0.6:1.0)*a+b);
		// cout << i << " " << ans << endl;
	}
	cout << ans << endl;
	return 0;
}