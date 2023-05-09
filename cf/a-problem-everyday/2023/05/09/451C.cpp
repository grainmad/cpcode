
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll n, k, d1, d2;

bool check(ll x, ll y, ll z) {
    return (x % 3 == 0 && y % 3 == 0 && z % 3 == 0 && 0 <= x / 3 &&
            0 <= y / 3 && 0 <= z / 3 && x / 3 <= n / 3 && y / 3 <= n / 3 &&
            z / 3 <= n / 3);
}

void sol() {
    cin >> n >> k >> d1 >> d2;
    if (n % 3) {
        cout << "no\n";
        return;
    }
    ll x1 = k + 2 * d1 + d2, y1 = k - d1 + d2, z1 = k - d1 - 2 * d2;
    ll x2 = k - 2 * d1 + d2, y2 = k + d1 + d2, z2 = k + d1 - 2 * d2;
    ll x3 = k + 2 * d1 - d2, y3 = k - d1 - d2, z3 = k - d1 + 2 * d2;
    ll x4 = k - 2 * d1 - d2, y4 = k + d1 - d2, z4 = k + d1 + 2 * d2;
    cout << ((check(x1, y1, z1) || check(x2, y2, z2) || check(x3, y3, z3) ||
              check(x4, y4, z4))
                 ? "yes\n"
                 : "no\n");
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
