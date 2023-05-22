#include <bits/stdc++.h>
// #define LOCAL
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

int g[4][4];

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) {
        cin >> i;
        i--;
    }

    auto b = a;
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        g[a[i]][b[i]]++;
    }
    for (int i = 0; i < 4; i++)
        g[i][i] = 0;
    int ans = 0;
    vector<int> c;
    function<void(int)> dfs = [&](int x) {
        if (x == 0) {
            // for (int i : c)
            //     cout << i << " ";
            // cout << "\n";
            int csz = c.size();
            int mn = n;
            for (int i = 0; i < csz; i++) {
                mn = min(mn, g[c[i]][c[(i + 1) % csz]]);
            }
            if (csz)
                ans += mn * (csz - 1);
            for (int i = 0; i < csz; i++) {
                g[c[i]][c[(i + 1) % csz]] -= mn;
            }
            return;
        }
        dfs(x - 1);
        for (int i = 0; i < 4; i++) {
            if (find(c.begin(), c.end(), i) == c.end()) {
                c.push_back(i);
                dfs(x - 1);
                c.pop_back();
            }
        }
    };
    dfs(4);
    cout << ans << "\n";
}
int main() {
#ifdef LOCAL
    auto start_time = clock();
    cerr << setprecision(3) << fixed;
#endif
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
#ifdef LOCAL
    auto end_time = clock();
    cerr << "Execution time: "
         << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}