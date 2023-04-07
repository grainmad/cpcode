#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll f[46];

int x, y, n;

bool check(int x1, int y1, int x2, int y2, int n, int o) {
    if (n == 0)
        return x1 == x && y1 == y;
    if (o) {
        if (y1 <= y && y < y1 + f[n])
            return check(x1, y1, x2, y1 + f[n], n - 1, 0);
        else if (y1 + f[n] <= y && y <= y2)
            return check(x1, y1 + f[n], x2, y2, n - 1, 0);
        else
            return false;
    } else {
        if (x1 <= x && x < x1 + f[n])
            return check(x1, y1, x1 + f[n], y2, n - 1, 1);
        else if (x1 + f[n] <= x && x <= x2)
            return check(x1 + f[n], y1, x2, y2, n - 1, 1);
        else
            return false;
    }
}

void sol() {
    f[0] = f[1] = 1;
    for (int i = 2; i <= 45; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    // for (int i = 0; i <= 45; i++) {
    //     cout << f[i] << "\n";
    // }
    cin >> n >> x >> y;
    cout << (check(1, 1, f[n], f[n + 1], n, 1) ? "YES\n" : "NO\n");
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