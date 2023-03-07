#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

vector<int> g[N];
set<pair<int, int>> st;
int ans[N];

int cnt = 0;
void getcnt(int u, int fa) {
    if (st.count({u, fa}))
        cnt++;
    for (int v : g[u]) {
        if (v == fa)
            continue;
        getcnt(v, u);
    }
}

void dfs(int u, int fa) {
    if (st.count({fa, u})) {
        cnt++;
    }
    if (st.count({u, fa})) {
        cnt--;
    }
    ans[u] = cnt;
    for (int v : g[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
    }
    if (st.count({fa, u})) {
        cnt--;
    }
    if (st.count({u, fa})) {
        cnt++;
    }
}

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        st.insert({x, y});
    }
    getcnt(1, 0);
    dfs(1, 0);
    int mn = *min_element(ans + 1, ans + n + 1);
    cout << mn << endl;
    for (int i = 1; i <= n; i++) {
        if (mn == ans[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
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