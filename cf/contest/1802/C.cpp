#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

int a[1 << 8][1 << 8];

void dfs(int x, int y, int sz, int val) {
    if (sz == 1) {
        a[x][y] = val - 1;
        return;
    }
    dfs(x, y, sz / 2, val - sz * sz / 4 * 3);
    dfs(x + sz / 2, y, sz / 2, val - sz * sz / 4 * 2);
    dfs(x, y + sz / 2, sz / 2, val - sz * sz / 4);
    dfs(x + sz / 2, y + sz / 2, sz / 2, val);
}

int check(int x, int y) {
    return a[x][y] ^ a[x + 1][y] ^ a[x][y + 1] ^ a[x + 1][y + 1];
}

void sol() {
    int n, m;
    cin >> n >> m;
    cout << n * m << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    // assert(check(8, 9) == 0);
}
int main() {
    dfs(0, 0, 1 << 8, 1 << 16);
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