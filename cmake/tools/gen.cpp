// 对拍数据生成器骨架 —— 复制到题目目录后只改「题目相关」段。
//
// 用法（由 cmake/stress.cmake 驱动，轮次号自动作为 argv[1] 传入当种子）：
//   ./gen 42                      # 手动跑：生成第 42 轮的数据
//   cmake -P cmake/stress.cmake <gen> <brute> <sol> 1000 10
//
// 原则：种子来自轮次号 => 每轮不同且可复现；规模压小更容易撞出边界情况。

#include <bits/stdc++.h>
using namespace std;

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

mt19937 rng;

int rnd(int l, int r) { return uniform_int_distribution<>(l, r)(rng); }

// 常用积木（按需取用/扩展）：
//   string rstr(int n, char lo = 'a', char hi = 'z')
//   vector<int> rvec(int n, int lo, int hi)            // 含重复元素
//   vector<int> rperm(int n)                           // 1..n 的随机排列
//   shuf(v)                                            // 原地打乱任意容器
//   树：对 i in [2,n] 连边 rnd(1, i-1)-i，边表可再 shuf() 打乱边序
//   图：按密度连边后 shuf()，注意自环/重边是否合法
string rstr(int n, char lo = 'a', char hi = 'z') {
    string s;
    while (n--) s += char(rnd(lo, hi));
    return s;
}
template <class T> void shuf(T& c) { shuffle(begin(c), end(c), rng); }
vector<int> rperm(int n) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    shuf(p);
    return p;
}

int main(int argc, char** argv) {
    // ===== 框架部分（所有题通用，勿动）=====
    rng.seed(argc > 1 ? (unsigned)atoi(argv[1]) : random_device{}());

    // ===== 题目相关部分（按题意改这里）=====
    // 例：单组数据，第一行 n，第二行 n 个数
    int n = rnd(1, 10);                    // 小规模：边界/暴力都跑得动
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
        printf("%d%c", rnd(-100, 100), i + 1 == n ? '\n' : ' ');
}
