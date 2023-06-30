
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
#define INF 0x3f3f3f3f
using namespace std;

// void sol() {
//     int n, s, k;
//     cin >> n >> s >> k;
//     s--;
//     vector<int> r(n);
//     for (auto& i : r)
//         cin >> i;
//     string c;
//     cin >> c;
//     vector<vector<int>> f(n, vector<int>(k + 51, INF));
//     for (int i = 0; i < n; i++) {
//         f[i][r[i]] = abs(i - s);
//     }
//     for (int j = 0; j <= k; j++) {
//         for (int i = 0; i < n; i++) {
//             for (int z = 0; z < n; z++) {
//                 if (c[i] == c[z] || r[i] >= r[z])
//                     continue;
//                 f[z][j + r[z]] = min(f[z][j + r[z]], f[i][j] + abs(i - z));
//             }
//         }
//     }
//     int ans = INF;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j <= 50; j++) {
//             ans = min(ans, f[i][j + k]);
//         }
//     }
//     // for (int i = 0; i < n; i++) {
//     //     for (int j = 0; j <= k; j++) {
//     //         cout << i << " " << j << " " << f[i][j] << "\n";
//     //     }
//     // }
//     if (ans == INF)
//         cout << "-1\n";
//     else
//         cout << ans << "\n";
// }

// void sol() {
//     int n, s, k;
//     cin >> n >> s >> k;
//     s--;
//     vector<int> r(n);
//     for (auto& i : r)
//         cin >> i;
//     string c;
//     cin >> c;
//     vector<vector<int>> f(n, vector<int>(k + 1, INF * 2));
//     // 在x位置还有y个要收集,所需的最小时间
//     function<int(int, int)> dfs = [&](int x, int y) {
//         if (r[x] >= y) {
//             // return f[x][y] = min(abs(x - s), f[x][y]);
//             return f[x][y] = abs(x - s);
//         }
//         if (f[x][y] != INF * 2)
//             return f[x][y];
//         f[x][y] = INF;
//         for (int i = 0; i < n; i++) {
//             if (c[x] != c[i] && r[i] < r[x])
//                 f[x][y] = min(f[x][y], dfs(i, y - r[x]) + abs(i - x));
//         }
//         return f[x][y];
//     };
//     int ans = INF;
//     for (int i = 0; i < n; i++) {
//         ans = min(ans, dfs(i, k));
//     }
//     if (ans == INF) {
//         cout << "-1\n";
//     } else {
//         cout << ans << "\n";
//     }
// }

void sol() {
    int n, s, k;
    cin >> n >> s >> k;
    s--;
    vector<int> r(n);
    for (auto& i : r)
        cin >> i;
    string c;
    cin >> c;
    vector<vector<int>> f(n, vector<int>(k + 1, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= r[i]; j++)
            f[i][j] = abs(i - s);
    }
    // 在x位置还有y个要收集,所需的最小时间
    for (int y = 0; y <= k; y++) {
        for (int x = 0; x < n; x++) {
            for (int i = 0; i < n; i++) {
                if (c[x] != c[i] && r[i] < r[x]) {
                    f[x][y] = min(f[x][y], f[i][max(0, y - r[x])] + abs(i - x));
                }
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= k; j++) {
    //         cout << i << " " << j << " " << f[i][j] << "\n";
    //     }
    // }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, f[i][k]);
    }
    if (ans == INF) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
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
