#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

vector<int> g[N];

map<vector<int>, int> h;
int val = 0;
int sym[N];

int dfs(int u, int fa) {
    vector<int> ch;
    for (int v : g[u]) {
        if (v == fa)
            continue;
        ch.push_back(dfs(v, u));
    }
    sort(ch.begin(), ch.end());
    if (h.count(ch) == 0) {
        map<int, int> mp;
        for (int i : ch)
            mp[i]++;
        int odd = 0, issym = 1;
        for (auto [i, j] : mp) {
            if (j % 2) {
                odd++;
                issym &= sym[i];
            }
                }
        sym[val] = odd < 2 && issym;
        h[ch] = val++;
    }
    return h[ch];
}

void sol() {
    int n;
    cin >> n;

    h.clear();
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 0; i < val; i++)
        sym[i] = 0;
    val = 0;

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout << (sym[dfs(1, 0)] ? "YES\n" : "NO\n");
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