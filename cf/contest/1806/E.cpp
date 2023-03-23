#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
#define SQ 320
#define MOD 998244353
#define INF 0x3f3f3f3f
using namespace std;

ll h[N][SQ + 5];  // h[i][id[j]] 节点i和j的ans
int cnt[N];       // cnt[i] 第i层的节点个数
int lev[N];       // lev[i] i节点在第几层
int id[N];        // id[i] i节点在所属层的第几个
ll a[N], p[N];

vector<int> g[N];

void dfs(int u, int l) {
    id[u] = cnt[l]++;
    lev[u] = l;
    for (int i : g[u]) {
        dfs(i, l + 1);
    }
}

ll ask(int x, int y) {
    if (!x && !y)
        return 0;
    if (cnt[lev[y]] < SQ && h[x][id[y]])
        return h[x][id[y]];
    ll ans = ask(p[x], p[y]) + a[x] * a[y];
    if (cnt[lev[y]] < SQ)
        return h[x][id[y]] = ans;
    return ans;
}

void sol() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        g[p[i]].push_back(i);
    }
    dfs(1, 0);
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << ask(x, y) << "\n";
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