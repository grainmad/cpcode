# 1637A - Sorting Parts

## 题意
给出一个数组，将数组截断分别排序再拼接，问是否是能不升序，是则输出YES，否则NO

## 分析
判断数组是否是升序的，是则经操作后任然是升序，输出NO，否则输出YES

## 代码
```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int num[10004];

void sol() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> num[i];
	}
	bool flag = true;
	int mx = num[0];
	for (int i=1; i<n; i++) {
		if (num[i] < mx) {
			flag = false;
			break;
		}
		mx = max(mx, num[i]);
	}
	cout << (flag?"NO":"YES") << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
```

# B. MEX and Array
## 题意
可以将一个数组分割成若干个连续的子数组，数组的cost值为拆分的子数组个数+每个子数组的mex值。
一个数组的mex值是该数组中最小的未出现的非负数。
求最大的数组的所有子数组的cost值之和。
## 分析
数组拆分的子数组大小不会影响cost值，可以拆分为长度为1的子数组
求每个子数组的cost是数组的区间和。
可求得前缀和，再枚举不同长度的子数组，每个cost只需O(1)可求得

## 代码
```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int a[105];

void sol() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		if (a[i] == 0) a[i] = 2;
		else a[i] = 1;
	}
	for (int i=1; i<=n; i++) {
		a[i] += a[i-1];
	}
	int ans = 0;
	for (int i=1; i<=n; i++) {
		for (int j=0; j+i<=n; j++) {
			ans += a[j+i]-a[j];
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}

```

# C. Andrew and Stones
## 题意
给一个数组，每次可以从数组中选三个元素，让中间的元素-2，两边的元素分别+1
问是否能让数组所有数都移动到首尾部，如果能输出最少操作次数，不能则输出-1
## 分析
如果有解，对于当前数$a_i, 0<i<n$:
若为奇数，必定需要被移入1个，然后对答案的贡献是$\frac{a_i+1}{2}$
若为偶数，必定对答案的贡献为$\frac{a_i}{2}$
如果无解，对于非首尾元素：奇数元素只有一个，或者全部为1
## 代码
```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int a[100005];

bool allone() {
	for (int i=1; i<n-1; i++) {
		if (a[i] != 1) return false;
	}
	return true;
}


void sol() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	if (allone() || n==3 && a[1]%2) {
		cout << "-1" << "\n";
		return ;
	}
	ll ans = 0;
	for (int i=1; i<n-1; i++) {
		ans += a[i]/2;
		if (a[i]%2) ans++;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
}
```