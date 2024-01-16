#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int sq = sqrt(n);
    vector<vector<ll>> p1(sq + 1, vector<ll>(n + 1, -1)),
        p2(sq + 1, vector<ll>(n + 1, -1));
    function<ll(int, int)> dfs1 =
        [&](int x, int y) {  // 步长为x, 以y位置为结尾的前缀和
            if (y <= 0)
                return 0LL;
            if (p1[x][y] != -1)
                return p1[x][y];
            return p1[x][y] = a[y] + dfs1(x, y - x);
        };
    function<ll(int, int)> dfs2 = [&](int x, int y) {
        if (y <= 0)
            return 0LL;
        if (p2[x][y] != -1)
            return p2[x][y];
        return p2[x][y] = (y + x - 1) / x * a[y] + dfs2(x, y - x);
    };
    while (q--) {
        ll s, d, k;
        cin >> s >> d >> k;
        if (d > sq) {
            ll ans = 0;
            for (int i = s, j = 1; i <= n && j <= k; i += d, j++) {
                ans += a[s + d * (j - 1)] * j;
            }
            cout << ans << " ";
        } else {
            // s s+d s+2d s+3d ... s+(k-1)d
            cout << dfs2(d, s + (k - 1) * d) - dfs2(d, s - d) -
                        ((s - 1) / d *
                         (dfs1(d, s + (k - 1) * d) - dfs1(d, s - d)))
                 << " ";
        }
    }
    cout << "\n";
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