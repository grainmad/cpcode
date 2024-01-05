
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 200005
#define MOD 998244353
using namespace std;

vector<int> g[N], st;
int c[N];
int fa[N];

int dfs(int u, int id) {
    st.push_back(u);
    if (c[u]) {
        cout << "Possible\n";
        vector<int> p;
        int t = u;
        while (t)
            p.push_back(t), t = fa[t];
        reverse(p.begin(), p.end());
        cout << p.size() << "\n";
        for (auto i : p) {
            cout << i << " ";
        }
        cout << "\n";
        cout << st.size() << "\n";
        for (auto i : st) {
            cout << i << " ";
        }
        cout << "\n";
        return 1;
    }
    c[u] = id;
    for (auto v : g[u]) {
        if (c[v] == id)
            continue;
        if (dfs(v, id))
            return 1;
        fa[v] = u;
    }
    st.pop_back();
    return 0;
}

void sol() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    st.push_back(s);
    for (int i = 0; i < g[s].size(); i++) {
        c[s] = i + 1;
        if (dfs(g[s][i], i + 1))
            return;
        fa[g[s][i]] = s;
    }
    cout << "Impossible\n";
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
