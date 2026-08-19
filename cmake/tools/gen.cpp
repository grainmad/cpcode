// 对拍数据生成器骨架 —— 复制到题目目录后只改「题目相关」段。
//
// 用法（由 cmake/stress.cmake 驱动，轮次号自动作为 argv[1] 传入当种子）：
//   ./gen 42                      # 手动跑：生成第 42 轮的数据
//   cmake -P cmake/stress.cmake <gen> <brute> <sol> 1000 10
//
// 原则：种子来自轮次号 => 每轮不同且可复现；规模压小更容易撞出边界情况。

#include <bits/stdc++.h>
using namespace std;

mt19937 rng;

int rnd(int l, int r) { return uniform_int_distribution<>(l, r)(rng); }

// 常用积木（按需取用/扩展）：
//   string rstr(int n, char lo = 'a', char hi = 'z')
//   vector<int> rvec(int n, int lo, int hi)            // 含重复元素
//   树：对 i in [2,n] 连边 rnd(1, i-1)-i               // 随机树
//   图：randShuffle 后按密度连边，注意自环/重边是否合法
string rstr(int n, char lo = 'a', char hi = 'z') {
    string s;
    while (n--) s += char(rnd(lo, hi));
    return s;
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
