
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
    for(auto [x,y]:mp) { if (s) s = 0; else os<<x<<": "<<y; }
    return os<<'}';
}

// 对拍 brute：精确最小色数（回溯） + 与 sol 相同的规范染色。
// 本题输出任意合法染色均算对，纯文本 diff 的 stress 要求两边输出一致，
// 故 brute 独立算出精确 k* 并校验规范染色合法、色数恰为 k*，不一致则
// 输出 BRUTE-REJECTED 使 diff 报错。仅面向小 n（gen 产 n ≤ 12）。
void sol() {
    int n;
    cin >> n;
    const int LIM = 1 << 17;              // 覆盖 n ≤ 65536 时所有 u^v
    static vector<char> np(LIM + 1, 0);
    if (!np[2]) {
        np[0] = np[1] = 1;
        for (int i = 2; i <= LIM; i++)
            if (!np[i])
                for (int j = i + i; j <= LIM; j += i) np[j] = 1;
    }
    auto is_edge = [&](int u, int v) { return u != v && !np[u ^ v]; };

    // 精确色数：k 从 1 起试，回溯判定 k 染色可行
    int kstar = n;
    for (int k = 1; k <= n; k++) {
        vector<int> c(n + 1, 0);
        function<bool(int)> dfs = [&](int u) -> bool {
            if (u > n) return true;
            for (int col = 1; col <= k; col++) {
                bool ok = true;
                for (int v = 1; v < u && ok; v++)       // 只看已染色的前缀
                    if (c[v] == col && is_edge(u, v)) ok = false;
                if (!ok) continue;
                c[u] = col;
                if (dfs(u + 1)) return true;
                c[u] = 0;
            }
            return false;
        };
        if (dfs(1)) { kstar = k; break; }
    }

    // 规范染色（与 sol 完全一致）
    vector<int> c(n + 1);
    if (n == 1) {
        c[1] = 1;
    } else if (n <= 3) {
        c[1] = 1;
        for (int i = 2; i <= n; i++) c[i] = 2;
    } else if (n <= 5) {
        int d[] = {0, 1, 2, 2, 3, 3};
        for (int i = 1; i <= n; i++) c[i] = d[i];
    } else {
        for (int i = 1; i <= n; i++) c[i] = i % 4 + 1;
    }
    int k = *max_element(c.begin() + 1, c.end());
    bool valid = true;
    for (int u = 1; u <= n && valid; u++)
        for (int v = u + 1; v <= n && valid; v++)
            if (c[u] == c[v] && is_edge(u, v)) valid = false;

    if (!valid || k != kstar) {
        cout << "BRUTE-REJECTED n=" << n << " k=" << k << " kstar=" << kstar << "\n";
        return;
    }
    cout << k << "\n";
    for (int i = 1; i <= n; i++) cout << c[i] << " \n"[i == n];
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
