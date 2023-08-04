
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

bool iszero(double x) {
    return fabs(x) < 1e-8;
}

void sol() {
    double c, m, p, v;
    cin >> c >> m >> p >> v;
    auto dfs = [&](auto self, double x, double y, double z, int stp) -> double {
        double rt = z * stp;
        if (!iszero(x)) {
            if (x > v) {
                if (iszero(y))
                    rt += x * self(self, x - v, 0, z + v, stp + 1);
                else
                    rt += x * self(self, x - v, y + v / 2, z + v / 2, stp + 1);
            } else {
                if (iszero(y))
                    rt += x * self(self, 0, 0, z + x, stp + 1);
                else
                    rt += x * self(self, 0, y + x / 2, z + x / 2, stp + 1);
            }
        }
        if (!iszero(y)) {
            if (y > v) {
                if (iszero(x))
                    rt += y * self(self, 0, y - v, z + v, stp + 1);
                else
                    rt += y * self(self, x + v / 2, y - v, z + v / 2, stp + 1);
            } else {
                if (iszero(x))
                    rt += y * self(self, 0, 0, z + y, stp + 1);
                else
                    rt += y * self(self, x + y / 2, 0, z + y / 2, stp + 1);
            }
        }
        return rt;
    };
    cout << dfs(dfs, c, m, p, 1) << "\n";
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
