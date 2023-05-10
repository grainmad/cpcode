#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 1000000007
using namespace std;

vector<int> g[N];
int sz[N];  // cnt[i] i的子树节点个数
int n, k;
ll ans = 0;
ll fpow(ll x, ll p) {
    ll rt = 1;
    while (p) {
        if (p & 1)
            rt = rt * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return rt;
}

ll dfs2(int u, int fa) {
    for (int v : g[u]) {
        if (v == fa)
            continue;
    }
}

void sol() {
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if (n % 2) {
        cout << "1\n";
    } else {
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