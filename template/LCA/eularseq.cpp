#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

vector<int> g[N];
vector<int> eulerTour;

int fc[N], dep[N];

void dfs(int u, int fno) {
    dep[u] = dep[fno] + 1;  // 每个节点的深度
    // 每个节点欧拉序中第一次出现的位置
    fc[u] = eulerTour.size();  // 每个节点第一次在欧拉序中出现的位置
    eulerTour.push_back(u);  // 欧拉序

    for (auto v : g[u]) {
        if (v == fno)
            continue;
        dfs(v, u);
        eulerTour.push_back(u);
    }
}
// 用st表维护欧拉序区间最小值，按照深度比较
struct ST {
    vector<vector<int>> st;  // st[i][j] 代表区间[i, i+2^j)最小值
    ST(const vector<int>& a) : st(a.size(), vector<int>(30)) {
        int sz = a.size();
        for (int i = 0; i < sz; i++)
            st[i][0] = a[i];
        for (int j = 1; (1 << j) <= sz; j++) {             // 区间大小
            for (int i = 0; i + (1 << j) - 1 < sz; i++) {  // 区间下限
                int x = st[i][j - 1], y = st[i + (1 << (j - 1))][j - 1];
                st[i][j] = dep[x] < dep[y] ? x : y;
            }
        }
    }
    int ask(int l, int r) {
        int k = 0;
        while ((1 << (k + 1)) <= r - l + 1)
            k++;
        int x = st[l][k], y = st[r - (1 << k) + 1][k];
        return dep[x] < dep[y] ? x : y;
    }
};

void sol() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(s, 0);
    ST st(eulerTour);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        // 获取x和y的lca
        cout << st.ask(min(fc[x], fc[y]), max(fc[x], fc[y])) << endl;
    }
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