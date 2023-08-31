#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

/*
优先用白色的错误
LRLR
.LR.
.LR.
LRLR

WBWB
.WB.
.WB.
BWWB
*/

void sol() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto& i : g)
        cin >> i;

    vector<string> ans(n, string(m, '.'));
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'U') {
                cnt++;
                if (cnt % 2) {
                    ans[i][j] = 'W';
                    ans[i + 1][j] = 'B';
                } else {
                    ans[i][j] = 'B';
                    ans[i + 1][j] = 'W';
                }
            }
        }
        if (cnt % 2) {
            cout << "-1\n";
            return;
        }
    }
    for (int j = 0; j < m; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (g[i][j] == 'L') {
                cnt++;
                if (cnt % 2) {
                    ans[i][j] = 'W';
                    ans[i][j + 1] = 'B';
                } else {
                    ans[i][j] = 'B';
                    ans[i][j + 1] = 'W';
                }
            }
        }
        if (cnt % 2) {
            cout << "-1\n";
            return;
        }
    }
    for (auto& i : ans) {
        cout << i << "\n";
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