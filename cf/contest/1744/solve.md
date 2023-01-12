[Problems - Codeforces](https://codeforces.com/contest/1744/problems)

# A. Number Replacement

## 题意

给出一个长度都为n的数组a和字符串s
问能否将所有a[i] 映射为 s[i]。

## 思路

哈希表建立映射若a[i] 已经映射了一个非s[i]，则输出NO，当所有a[i]都满足则YES。

## 代码

```cpp
#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 505
using namespace std;

int a[N];

void sol() {
	int n; string s;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	cin >> s;
	map<int,char> mp;
	for (int i=0; i<n; i++) {
		if (!mp.count(a[i])) {
			mp[a[i]] = s[i];
		}
		if (mp[a[i]] != s[i]) {
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef SINGLE_INPUT
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
#else
	sol();
#endif
	return 0;
}
```

# B. Even-Odd Increments

## 题意

给出一个长度为n的数组a，以及q次操作。
每次操作有两种类型：
1. 给所有偶数加上x
2. 给所有计数加上x
每次操作后都需要输出新数组的和。

## 思路

根据每次操作的类型，添加的x的奇偶性，数组中奇偶数的个数，可以知道为总和贡献了多少，并在操作后更新奇偶数的个数。

## 代码

```cpp
#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

void sol() {
	int n, q; cin >> n >> q;
	ll s = 0, e = 0, o = 0;
	for (int i=0; i<n; i++) {
		ll x; cin >> x;
		if (x%2) o++;
		else e++;
		s += x;
	}

	for (int i=0; i<q; i++) {
		int tp, x;
		cin >> tp >> x;
		if(tp) {
			s += o*x;
			if (x%2) e = n, o = 0;
		} else {
			s += e*x;
			if (x%2) e = 0, o = n; 
		}
		cout << s << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef SINGLE_INPUT
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
#else
	sol();
#endif
	return 0;
}
```

# C. Traffic Light

## 题意

给你一个长度为n的字符串`s`，和字符`c`。
字符串只包含`’r’`，`’y’`，`’g’`，分别代表红，黄，绿，当前的颜色是`c`，字符串中可能由多个`c`这种颜色，求每一个`c`右侧离他最近的`g`之间的距离的最大值。字符串是首位相接的循环字符串。

## 思路

直接拼接一次s，在两倍长度的字符串内一定可以贪心找到最大距离。

## 代码

```cpp
#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

void sol() {
	int n; string c, s;
	cin >> n >> c >> s;
	if (c[0] == 'g') {
		cout << "0\n";
		return ;
	}
	s += s;
	int p = -1, ans = 0;
	for (int i=0; i<2*n; i++) {
		if (p == -1 && s[i] == c[0]) {
			p = i;
		}
		if (p != -1 && s[i] == 'g') {
			ans = max(ans, i-p);
			p = -1;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef SINGLE_INPUT
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
#else
	sol();
#endif
	return 0;
}
```

# D. Divisibility by 2^n

## 题意

给出一个长度为`n`的数组`a`，我们可以对数组进行多次操作，每次操作可以让`a[i] = a[i]*i`, （数组下标从`1`开始），但是每个下标最多只能操作一次，我们的目标是用最少的次数使得a的所有元素积成为$2^n$的倍数，若没有答案则输出-1。

## 思路

首先我们可以看原始数组之积中的2因子个数是否不小于n，是则不需要任何操作。否则，我们会选择每能贡献最多2因子的下标进行操作，直到满足2因子的个数大于等于n为止，若n次操作后都不满足则输出-1.

## 代码

```cpp
#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

void sol() {
	int n;
	cin >> n;
	vector<int> p;
	int cnt = 0;
	for (int i=1; i<=n; i++) {
		ll x;
		cin >> x;
		while (x%2==0) {
			cnt++;
			x >>= 1;
		}
		int u = i, c=0;
		while (u%2==0) {
			u>>=1;
			c++;
		}
		if (c) p.push_back(c);
	}
	sort(p.rbegin(), p.rend());
	if (cnt >= n) {
		cout << "0\n";
		return ;
	}
	for (int i=0; i<p.size(); i++) {
		cnt += p[i];
		if (cnt >= n) {
			cout << i+1 << "\n";
			return ;
		}
	}
	cout << "-1\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef SINGLE_INPUT
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
#else
	sol();
#endif
	return 0;
}
```

# E1. Divisible Numbers (easy version)

## 题意

给你四个整数a,b,c,d, 满足$1 \leq a < c \leq 10^5$，$1 \leq b < d \leq 10^5$，求整数x，y，使得$a < x \leq c, b < y \leq d$，
且x*y 被a*b整除

## 思路

注意到数据范围1e5, 我们可以枚举x或y来求另一个y或x，这里我们枚举x，对于任意a<x≤c，如何找到一个最小的y使得x*y能整除a*b，我们找到x和a*b公共部分，让a*b移除这一部分，剩余的部分乘以x才能是ab的倍数，所以`y = a*b/gcd(x, a*b)` 是最小使得x*y能整除a*b的数。然而此时的y应该满足b<y≤d这一条件。我们要让y倍增到这一范围内，可以让$y = (\lfloor \frac{b}{y} \rfloor+1) * y$, 然后判断$y≤d$; 或者让$y= (\lfloor \frac{d}{y} \rfloor) * y$，然后判断$b<y$

## 代码

```cpp
#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

void sol() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll m = a*b;
	for (ll x=a+1; x<=c; x++) {
		ll y = m/__gcd(m, x);
		// if (y<=b) y = (b/y+1)*y;
		y = d/y*y;
		if (b<y && y<=d) {
			cout << x << " " << y << endl;
			return ;
		}
	}
	cout << "-1 -1\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef SINGLE_INPUT
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
#else
	sol();
#endif
	return 0;
}
```

# E2. Divisible Numbers (hard version)

## 题意

与E1只有数据范围不同，$1 \leq a < c \leq 10^9, 1 \leq b < d \leq 10^9$

## 思路

这次枚举x是不行了，我们试想什么样的数是a*b的倍数呢？如果这个数是a*b的倍数，那么也一定是a的因子及b的因子的倍数，a的因子量级大概是$a^{\frac{1}{3}}$,大概在1e3左右，b也如此，那么枚举a和b的因子数量级在1e6, 若当前枚举的a与b的因子之积为x，则y=a*b/gcd(a*b, x)是最小使得x*y成为a*b的倍数的数，然后判断能否倍增x到(a,c], y到(b,d]即可。

## 代码

```cpp
#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

void sol() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<ll> fa, fb;
	for (int i=1; i*i<=a; i++) {
		if (a%i==0) fa.push_back(i), fa.push_back(a/i);
	}
	for (int i=1; i*i<=b; i++) {
		if (b%i==0) fb.push_back(i), fb.push_back(b/i);
	}
	for (ll i:fa) {
		for (ll j:fb) {
			ll x = i*j, y = a*b/(i*j);
			if (x<=a) x = (a/x+1)*x;
			if (y<=b) y = (b/y+1)*y;
			if (x<=c && y<=d) {
				cout << x << " " << y << "\n";
				return ;
			}
		}
	}
	cout << "-1 -1\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef SINGLE_INPUT
	int t;
	cin >> t;
	while (t--) {
		sol();
	}
#else
	sol();
#endif
	return 0;
}
```