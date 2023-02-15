#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

vector<int> g[N];
int d[N];
int ans[N];
int vis[N];

void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        ans[i] = i;
    }
    sort(ans + 1, ans + n + 1, [&](int x, int y) { return d[x] < d[y]; });
    for (int i = 1; i <= n; i++) {
        set<int> st;
        for (int j : g[ans[i]]) {
            if (vis[j])
                st.insert(vis[j]);
        }
        if (st.size() == d[ans[i]] - 1 &&
            (st.empty() || *st.rbegin() < d[ans[i]])) {
            vis[ans[i]] = d[ans[i]];
        } else {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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