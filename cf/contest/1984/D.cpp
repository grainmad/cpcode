#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

random_device seed;
ranlux48 engine(seed());
int random(int l, int r) {
    uniform_int_distribution<> distrib(l, r);
    return distrib(engine);
}
template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p) {
    return os<<'['<<p.first<<", "<<p.second<<']';
}
template<class t> ostream& operator<<(ostream& os,const vector<t>& v) {
    os<<'['; int s = 1;
    for(auto e:v) { if (s) s = 0; else os << ", "; os << e; }
    return os<<']';
}
template<class t,class u> ostream& operator<<(ostream& os,const map<t,u>& mp){
    os<<'{'; int s = 1;
    for(auto [x,y]:mp) { if (s) s = 0; else os << ", "; os<<x<<": "<<y; }
    return os<<'}';
}

vector<int> z_function(string s) {
	int n = (int)s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i<=r) {
			z[i] = min(z[i-l], r-i+1);
		}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			l = i;
			r = i + z[i];
			++z[i];
		}
	}
	return z;
}

void sol() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> na(n+1, n);
    for (int i=n-1; i>=0; i--) {
        if (s[i] != 'a') na[i] = i;
        else na[i] = na[i+1];
    }
    int na0 = na[0];
    if (na0 == n) {
        cout << n-1 << "\n";
        return ;
    }
    string t = s.substr(na0);
    auto zf = z_function(t);
    ll ans = 0;
    for (int i=1; i+na0<=n; i++) {
        int c = i+na0;
        int ok = 1;
        int mn = na0;
        while (c < n && na[c] != n) {
            mn = min(mn, na[c]-c); // 这一段全为a，维护所有全为a的最小长度，所有匹配的长度为i的串前面都可以添加最多mn个a。
            c = na[c]; // 落点为a，跳过后面全为a的区域
            if (zf[c-na0]<i) { // s[na0...] = s[c...] 匹配长度必须大于等于i，才能保证长度为i的串存在答案
                ok = 0;
                break;
            }
            c += i; // 已经找到一个长度为i的匹配串，内层循环最多n/i
        }
        if (ok) ans += mn+1;
    }
    cout << ans << "\n";
}

int main() {
    cout << setprecision(15) << fixed;
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