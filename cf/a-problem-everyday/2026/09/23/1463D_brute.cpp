// 对拍暴力解骨架 —— 把题意直译成最笨的正确写法（O(n^2)/O(2^n) 都行，n 小）。
// 与 sol 读同样的输入格式、输出同样的答案；由 cmake/stress.cmake 驱动对比。

#include <bits/stdc++.h>
// #define SINGLE_INPUT     // 多测时注释掉这行；单测时取消注释
#define ll long long
#define ull unsigned long long
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
template<class t> ostream& operator<<(ostream& os,const set<t>& v) {
    os<<'['; int s = 1;
    for(auto e:v) { if (s) s = 0; else os << ", "; os << e; }
    return os<<']';
}
template<class t,class u> ostream& operator<<(ostream& os,const map<t,u>& mp){
    os<<'{'; int s = 1;
    for(auto [x,y]:mp) { if (s) s = 0; else os << ", "; os<<x<<": "<<y; }
    return os<<'}';
}

void sol() {
    // 读入 -> 求解 -> 输出（cout << ... << "\n"）
    // 精确参考解（n<=15）：配对即 B 与 A=[1,2n]\B 的完美双射，b<a 计入 x。
    // dp[mask] = 已占用的 A 下标集合为 mask（b[0..popcount(mask)-1] 已配好）时，
    // 剩余配对可取到的 min 对个数集合（ull 位掩码，第 x 位 = 可达 x）。
    // 转移：下一个待配的 b 是 b[popcount(mask)]，枚举未用 A 下标 j，
    // dp[mask] |= dp[mask|1<<j] << (b[i] < a[j])。答案 = popcount(dp[0])。
    int n;
    cin >> n;
    vector<int> b(n);
    for (auto &x : b) cin >> x;
    sort(b.begin(), b.end());
    vector<char> inB(2 * n + 2, 0);
    for (int x : b) inB[x] = 1;
    vector<int> a;
    a.reserve(n);
    for (int v = 1; v <= 2 * n; v++)
        if (!inB[v]) a.push_back(v);

    int full = (1 << n) - 1;
    vector<unsigned long long> dp(full + 1, 0);
    dp[full] = 1;
    for (int mask = full - 1; mask >= 0; mask--) {
        int i = __builtin_popcount(mask);
        unsigned long long cur = 0;
        for (int j = 0; j < n; j++) {
            if (mask >> j & 1) continue;
            cur |= dp[mask | 1 << j] << (b[i] < a[j] ? 1 : 0);
        }
        dp[mask] = cur;
    }
    cout << __builtin_popcountll(dp[0]) << "\n";
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
