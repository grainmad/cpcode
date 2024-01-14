
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

int x[N], y[N], w[N];

struct Dsu {
    vector<ll> fa;
    Dsu(int sz) : fa(sz, -1) {}

    int find(int u) {
        return fa[u] < 0 ? u : fa[u] = find(fa[u]);  // 路径压缩
    }

    void unite(int u, int v) {
        int fu = find(u), fv = find(v);
        if (fu != fv) {
            // 小集合fu 加入到 大集合fv，按秩归并
            if (fa[fu] < fa[fv])
                swap(fu, fv);
            fa[fv] += fa[fu];
            fa[fu] = fv;
        }
    }
};

void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i] >> w[i];
    }
    auto check = [&](int msk) {
        Dsu dsu(n + 1);
        for (int i = 1; i <= m; i++) {
            if ((w[i] | msk) == msk) {
                dsu.unite(x[i], y[i]);
            }
        }
        int neg = 0;
        for (int i = 1; i <= n; i++) {
            if (dsu.fa[i] < 0)
                neg++;
        }
        return neg == 1;  // 只有一个根，可以生成树
    };
    int mask = (1 << 30) - 1;
    for (int i = 29; i >= 0; i--) {
        if (check(mask ^ (1 << i)))
            mask ^= (1 << i);
    }
    cout << mask << "\n";
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
