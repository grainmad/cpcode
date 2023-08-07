
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 200005
#define MOD 998244353
using namespace std;

vector<int> g[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        set<int> st;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            st.insert(x);
        }
        int ok = 1;
        auto dfs = [&](auto& self, int x, int fa) -> int {
            int cnt = 0;
            for (int y : g[x]) {
                if (y == fa)
                    continue;
                int rt = self(self, y, x);
                if (rt == 1)
                    cnt++;
                else if (rt == 2) {
                    if (st.count(x)) {
                        ok = 0;
                        return -1;
                    }
                    cnt += 2;
                } else if (rt != 0)
                    return -1;
            }
            if (cnt == 0)
                return st.count(x);
            if (cnt == 1 || cnt == 2)
                return cnt;
            ok = 0;
            return -1;
        };
        dfs(dfs, 1, -1);
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
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
