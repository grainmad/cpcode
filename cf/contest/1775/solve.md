[Complete problemset](https://codeforces.com/contest/1775/problems)

# A1. Gardener and the Capybaras (easy version)

## 题意

一个只由`’a’`和`‘b’` 组成的字符串s，问可否分成三个子串a，b，c，使得a≤b≥c 或者 a≥b≤c

字符串长度n不超过100

## 思路

枚举拆分位置即可

## 代码

```cpp
#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
	string s;
	cin >> s;
	int n = s.size();
	for (int i=1; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			auto a = s.substr(0,i), b = s.substr(i,j-i), c = s.substr(j);
			if (a<=b && c<=b || a>=b && c>=b) {
				cout << a << " " << b << " " << c << endl;
				return ;
			}
		}
	}
	cout << ":(" << endl;
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

# A2. Gardener and the Capybaras (hard version)

## 题意

一个只由`’a’`和`‘b’` 组成的字符串s，问可否分成三个子串a，b，c，使得a≤b≥c 或者 a≥b≤c

字符串长度n不超过200000

## 思路

贪心

对于a≤b≥c的情况，我们在第二个字符到倒数第二个字符间寻找第一个`’b’`的位置p，让a = s[0], b=s[1:p], c=s[p+1,n-1]。

对于a≥b≤c的情况，我们在第二个字符到倒数第二个字符间寻找第一个`’a’`的位置p，让a = s[0,p-1], b=s[p], c=s[p+1,n-1]。

## 代码

```cpp
#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
	string s;
	cin >> s;
	int n = s.size();
	for (int i=1; i<n-1; i++) {
		if (s[i] == 'a') {
			string a = s.substr(0,i), b = "a", c = s.substr(i+1);
			if (a>=b && b<=c) {
				cout << a << " " << b << " " << c << endl;
				return ;
			}
			break;
		}
	}
	for (int i=1; i<n-1; i++) {
		if (s[i] == 'b') {
			string a = s.substr(0,i), b = s.substr(i,n-i-1), c = s.substr(n-1);
			if (a<=b && b>=c) {
				cout << a << " " << b << " " << c << endl;
				return ;
			}
			break;
		}
	}
	cout << ":(\n";
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

# B. Gardener and the Array

## 题意

有n个数，已知n个数可能很大，于是给出n个数的二进制位。问能否找到两个不同的子序列使得两个子序列的**或和**相等

## 思路

我们知道或和是不会随着数增加而减少的，我们可以寻找两个特殊的子序列。

其中一个是所有的n个数，另一个则可以是n-1个数。

我们检查去掉的这个数后会不会和n个数的或和相等即可。

## 代码

```cpp
#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

bool check(set<int>& a, map<int,int>& b) {
	for (int i:a) {
		if (!b.count(i) || b[i] == 1) return false;
	}
	return true;
}

void sol() {
	int n;
	cin >> n;
	std::vector<set<int>> st(n);
	map<int,int> v;
	for (int i=0; i<n; i++) {
		int ki, p; cin >> ki;
		for (int j=0; j<ki; j++) {
			cin >> p;
			st[i].insert(p);
			v[p]++;
		}
	}
	for (int i=0; i<n; i++) {
		if (check(st[i], v)) {
			cout << "yes\n";
			return ;
		}
	}
	cout << "no\n";
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

# C. Interesting Sequence

## 题意

给出两个数$n$和$x$，是否存在$n \& (n+1)\& \dots \& m=x$的$m$，存在则输出，否则输出-1。

## 思路

我们知道**与和**会不断减小，设$n$的由低到高位第$i$位二进制位为$n_i$，保证存在m的必要条件是$n_i \ge x_i$。

另外如果p是低位第一个满足$n_p = 1$且$x_p = 1$的位置，q是低位第一个满足$n_q=1$且$x_q=0$的位置。需要满足$q+1\le p$

此时答案就是n的末q位，置为0，然后第q+1位，置为1

## 代码

```cpp
#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
	ll n, x;
	cin >> n >> x;
	int _10 = -1, _11 = 64;
	for (int i=0; i<63; i++) {
		int a = n>>i&1, b = x>>i&1;
		if (a == 1 && b == 1) _11 = i;
		if (a == 1 && b == 0) _10 = i;
		if (a == 0 && b == 1) {
			cout << "-1\n";
			return ;	
		}
	}
	for (int i=62; i>=0; i--) {
		int a = n>>i&1, b = x>>i&1;
		if (a == 1 && b == 1) _11 = i;
	}
	if (_10 == -1) {
		cout << n << "\n";
		return ;
	}
	if (_10 + 1 >= _11) {
		cout << "-1\n";
		return ;
	}
	cout << ((n>>_10+1)<<_10+1|1LL<<_10+1) << endl;
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

# D. Friendly Spiders

## 题意

给出大小为n（2≤n≤3e5）的数组a（1≤a[i]≤3e5），若数u和v不互质则存在一条边，求从第s个数到第k个数的最短路径

## 思路

直接建边求最短路由于边数太多会超时。

我们可以让每个数都连向虚拟节点：它们的质因数。由于小于3e5质因数的个数实际很少，只有100多个。这样连的边数大大减少，然后求bfs，求出路径，去除路径上虚拟节点。

## 代码

```cpp
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 300005
#define MAXN 550
#define MOD 998244353
using namespace std;

std::vector<int> g[N*2];
int pre[N*2], vis[N*2];

bool nprime[MAXN];
vector <int> prime;

void get_prime() {
	memset(nprime, 0, sizeof(nprime));
	int n = (int) sqrt(MAXN+0.5);
	for (int i=2; i<n; i++) {
		if (!nprime[i]) {
			for (int j=i*i; j<MAXN; j+=i) {
				nprime[j] = true;
			}
		}
	}
	for (int i=2; i<MAXN; i++) {
		if (!nprime[i]) {
			prime.push_back(i);
			// cout << i << endl;
		}
	}
	// cout << prime.size();
}

void sol() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin >> a[i];
	int x, y;
	cin >> x >> y;
	x--; y--;
	for (int i=0; i<a.size(); i++) {
		int u = a[i];
		for (int j:prime) {
			if (u%j) continue;
			g[N+j].push_back(i);
			g[i].push_back(N+j);
			while (u%j == 0) {
				u/=j;
			}
		}
		if (u != 1) {
			g[N+u].push_back(i);
			g[i].push_back(N+u);
		}
	}

	queue<int> q;
	q.push(y);
	vis[y] = 1;
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i:g[u]) {
			if (!vis[i]) {
				vis[i] = 1;
				pre[i] = u;
				q.push(i);
			}
		}
	}
	if (vis[x] == 0) {
		cout << "-1\n";
		return ;
	}
	vector<int> stp;
	while (x != y) {
		if(x<N) stp.push_back(x+1);
		x = pre[x];
	}
	stp.push_back(y+1);
	cout << stp.size() << "\n";
	for (int i:stp) {
		cout << i << " ";
	}
	cout << "\n";

}

int main() {
	get_prime();
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

# E. The Human Equation

## 题意

给出一个数组，每次可以选取一个子序列，然后让子序列的奇数位置的数+1，偶数位置的数-1，或者奇数的位置的数-1，偶数位置的数+1。问让所有的数都为0的最小操作次数.

## 思路

其实每次我们相当于任选一些区间让这些区间+1或-1。

我们要找到区间和的绝对值最大的区间，设这个区间的绝对值为s

我们要操作的次数至少也要s次。

## 代码

```cpp
#include <bits/stdc++.h>
//#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
	int n;
	cin >> n;
	std::vector<ll> v(n);
	std::vector<ll> p(n+1);
	for (int i=0; i<n; i++) cin >> v[i];
	for (int i=1; i<=n; i++) p[i] = p[i-1]+v[i-1];
	cout << *max_element(p.begin(), p.end()) - *min_element(p.begin(), p.end()) << "\n";
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