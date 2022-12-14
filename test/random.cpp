#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

default_random_engine e(time(0));//生成无符号随机整数
//0到1（包含)的均匀分布
uniform_real_distribution<double> u(0,1);

void sol() {
	for (int i=0; i<10; i++) {
		cout << u(e) << " ";
	}
	cout << exp(-9) << endl;
	map<int,int> mp = {{1,2},{3,4},{5,6}};
	for (auto [i,j]:mp) {
		cout << i << " " << j << endl;
	}
}

int main() {
	sol();
	return 0;
}