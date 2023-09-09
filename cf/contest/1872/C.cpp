#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int l, r;
    cin >> l >> r;
    if (l == r && l % 2) {
        for (int i = 2; i * i <= r; i++) {
            if (r % i == 0) {
                cout << i << " " << i * (r / i - 1) << "\n";
                return;
            }
        }
        cout << "-1\n";
        return;
    }
    if (r % 2)
        r--;
    if (l > r) {
        cout << "-1\n";
    } else if (r != 2) {
        cout << 2 << " " << r - 2 << "\n";
    } else {
        cout << "-1\n";
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