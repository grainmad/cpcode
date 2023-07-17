#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, t, m;
    cin >> n >> t >> m;
    vector<pair<int, int>> cd(m);
    for (auto& [i, j] : cd) {
        cin >> i >> j;
        i--;
        j--;
    }

    vector<int> a(n, -1);  // a[i] 第i个数的队伍
    int ans = 0;
    // 需要保证每个队伍都至少一人，队伍无区别，人有区别。
    auto dfs = [&](auto self, int x, int y) -> void {
        if (y > t)
            return;
        if (x == n) {
            if (y != t)
                return;
            int ok = 1;
            for (auto [i, j] : cd) {
                if (a[i] == a[j]) {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
            return;
        }
        for (int i = 0; i < y; i++) {
            a[x] = i;
            self(self, x + 1, y);
            a[x] = -1;
        }
        a[x] = y;
        self(self, x + 1, y + 1);
        a[x] = -1;
    };
    dfs(dfs, 0, 0);
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