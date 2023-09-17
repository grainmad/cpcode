
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto& i : g) {
        cin >> i;
    }
    auto check0 = [&]() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] != 'A') {
                    return false;
                }
            }
        }
        cout << "0\n";
        return true;
    };
    auto check1 = [&]() {
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            c1 += g[i][0] == 'A';
            c2 += g[i][m - 1] == 'A';
        }
        if (c1 == n || c2 == n) {
            cout << "1\n";
            return true;
        }
        int r1 = 0, r2 = 0;
        for (int i = 0; i < m; i++) {
            r1 += g[0][i] == 'A';
            r2 += g[n - 1][i] == 'A';
        }
        if (r1 == m || r2 == m) {
            cout << "1\n";
            return true;
        }
        return false;
    };
    auto check2 = [&]() {
        if (g[0][0] == 'A' || g[0][m - 1] == 'A' || g[n - 1][0] == 'A' ||
            g[n - 1][m - 1] == 'A') {
            cout << "2\n";
            return true;
        }

        for (int i = 1; i < n - 1; i++) {
            int c = 0;
            for (int j = 0; j < m; j++) {
                c += g[i][j] == 'A';
            }
            if (c == m) {
                cout << "2\n";
                return true;
            }
        }
        for (int i = 1; i < m - 1; i++) {
            int c = 0;
            for (int j = 0; j < n; j++) {
                c += g[j][i] == 'A';
            }
            if (c == n) {
                cout << "2\n";
                return true;
            }
        }
        return false;
    };
    auto check3 = [&]() {
        for (int i = 1; i < n - 1; i++) {
            int c = 0;
            if (g[i][0] == 'A' || g[i][m - 1] == 'A') {
                cout << "3\n";
                return true;
            }
        }
        for (int i = 1; i < m - 1; i++) {
            int c = 0;
            if (g[0][i] == 'A' || g[n - 1][i] == 'A') {
                cout << "3\n";
                return true;
            }
        }
        return false;
    };
    auto check4 = [&]() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 'A') {
                    cout << "4\n";
                    return true;
                }
            }
        }
        return false;
    };
    check0() || check1() || check2() || check3() || check4() ||
        cout << "MORTAL\n";
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
