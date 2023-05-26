
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 705
#define MOD 1000000007
using namespace std;

ll f[N][N][3][3];

void sol() {
    vector<pair<int, int>> dir = {{0, 1}, {0, 2}, {1, 0}, {2, 0}};
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ne(n, -1), st;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            ne[st.back()] = i;
            st.pop_back();
        } else {
            st.push_back(i);
        }
    }
    // for (int i : ne) {
    //     cout << i << " ";
    // }
    // cout << endl;
    memset(f, -1, sizeof(f));
    function<ll(int, int, int, int)> dfs = [&](int l, int r, int cl, int cr) {
        if (f[l][r][cl][cr] != -1) {
            return f[l][r][cl][cr];
        }
        ll rt = 0;
        if (ne[l] == r) {
            if (cl == cr || cl && cr) {
                // cout << l << " " << r << " " << cl << " " << cr << " \n";
                return f[l][r][cl][cr] = 0;
            }
            if (l + 1 == r) {
                // cout << l << " " << r << " " << cl << " " << cr << " 1\n";
                return f[l][r][cl][cr] = 1;
            }
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    if (x == cl && x)
                        continue;
                    if (y == cr && y)
                        continue;
                    // cout << cl << " " << x << " " << y << " " << cr << endl;
                    rt += dfs(l + 1, r - 1, x, y);
                    rt %= MOD;
                }
            }
        } else {
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    if (x == y && x)
                        continue;
                    rt += dfs(l, ne[l], cl, x) * dfs(ne[l] + 1, r, y, cr) % MOD;
                    rt %= MOD;
                }
            }
        }
        // cout << l << " " << r << " " << cl << " " << cr << " " << rt << "\n";
        return f[l][r][cl][cr] = rt;
    };
    ll ans = 0;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            ans += dfs(0, n - 1, x, y);
            ans %= MOD;
        }
    }
    cout << ans << "\n";
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
