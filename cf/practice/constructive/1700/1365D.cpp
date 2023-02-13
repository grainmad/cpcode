#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 55
#define MOD 998244353
using namespace std;

char a[N][N];

void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (a[i] + 1);
    }
    int G = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'G')
                G++;
            if (a[i][j] == 'B') {
                for (int k = 0; k < 4; k++) {
                    int x = i + (k - 1) % 2;
                    int y = j + (k - 2) % 2;
                    if (a[x][y] == 'G') {
                        cout << "NO\n";
                        return;
                    }
                    if (a[x][y] == '.')
                        a[x][y] = '#';
                }
            }
        }
    }
    if (G == 0) {
        cout << "YES\n";
        return;
    }
    if (a[n][m] == '#') {
        cout << "NO\n";
        return;
    }
    queue<pair<int, int>> q;
    q.emplace(n, m);
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        if (G == 0)
            break;
        for (int i = 0; i < 4; i++) {
            int mx = x + (i - 2) % 2;
            int my = y + (i - 1) % 2;
            if (mx < 1 || mx > n || my < 1 || my > m || a[mx][my] == '#')
                continue;
            if (a[mx][my] == 'G')
                G--;
            a[mx][my] = '#';
            q.emplace(mx, my);
        }
    }
    cout << (G ? "NO\n" : "YES\n");
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