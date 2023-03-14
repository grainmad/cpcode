#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

string a = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void sol() {
    int r, c, k;
    cin >> r >> c >> k;
    vector<string> g(r);
    int rice = 0;
    for (int i = 0; i < r; i++) {
        cin >> g[i];
        rice += count(g[i].begin(), g[i].end(), 'R');
    }
    int cnt = 0, p = 0;
    for (int i = 0; i < r; i++) {
        if (i % 2) {
            for (int j = 0; j < c; j++) {
                if (g[i][j] == 'R')
                    cnt++;
                g[i][j] = a[min(p, k - 1)];
                if (cnt == rice / k + (p < rice % k ? 1 : 0)) {
                    cnt = 0;
                    p++;
                }
            }
        } else {
            for (int j = c - 1; j >= 0; j--) {
                if (g[i][j] == 'R')
                    cnt++;
                g[i][j] = a[min(p, k - 1)];
                if (cnt == rice / k + (p < rice % k ? 1 : 0)) {
                    cnt = 0;
                    p++;
                }
            }
        }
    }
    for (int i = 0; i < r; i++) {
        cout << g[i] << "\n";
    }
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