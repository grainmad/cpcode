#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (string& i : s)
        cin >> i;
    auto check = [&](int x1, int y1, int x2, int y2) {
        // cout << x1 << " " << y1 << ", " << x2 << " " << y2 << endl;
        int f1 = 1, f2 = 1;
        for (int i = x1; i <= x2; i++) {
            if ('W' == s[i][y1])
                f1 = 0;
        }
        for (int i = y1; i <= y2; i++) {
            if ('W' == s[x2][i])
                f1 = 0;
        }
        for (int i = x1; i <= x2; i++) {
            if ('W' == s[i][y2])
                f2 = 0;
        }
        for (int i = y1; i <= y2; i++) {
            if ('W' == s[x1][i])
                f2 = 0;
        }
        // cout << f1 << " " << f2 << endl;
        return f1 || f2;
    };
    for (int i = 0; i < n * m; i++) {
        for (int j = i + 1; j < n * m; j++) {
            int x1 = i / m, y1 = i % m, x2 = j / m, y2 = j % m;
            if ('B' == s[x2][y2] && s[x1][y1] == s[x2][y2]) {
                if (!check(x1, y1, x2, y2)) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
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