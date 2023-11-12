#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

struct Wdsu {
    vector<ll> fa, wt;
    Wdsu(int sz) : fa(sz, -1), wt(sz, 0) {}
    int find(int u) {
        if (fa[u] < 0)
            return u;
        int v = find(fa[u]);
        wt[u] += wt[fa[u]];
        return fa[u] = v;
    }

    // 尝试u和v纳入同一集合，当路径权值冲突返回false
    /*
    u --val--> v
    u --wt[u]--> fu
    v --wt[v]--> fv

    fu == fv
    u --val--> v --wt[v]--> fv
    val + wt[v] = wt[u]

    fu !=fv
    fu --(val+wt[v]-wt[u])--> fv

    */
    int unite(int u, int v, int val) {
        int fu = find(u), fv = find(v);
        if (fu == fv) {
            return wt[u] == val + wt[v];
        }
        fa[fu] = fv;
        wt[fu] = val + wt[v] - wt[u];
        return true;
    }
};

void sol() {
    int n, q;
    cin >> n >> q;
    Wdsu wdsu(n + 5);
    for (int i = 1; i <= q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (wdsu.unite(b, a, c)) {
            cout << i << " ";
        }
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