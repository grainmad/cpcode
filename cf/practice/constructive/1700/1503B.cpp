#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll X1, Y1, X2, Y2, r1, r2, n;

void R1(int x) {
    cout << x << " " << X1 << " " << Y1 << endl;
    Y1 += 2;
    if (Y1 > n) {
        X1++;
        Y1 = X1 % 2 ? 2 : 1;
    }
    r1--;
}

void R2(int x) {
    cout << x << " " << X2 << " " << Y2 << endl;
    Y2 += 2;
    if (Y2 > n) {
        X2++;
        Y2 = X2 % 2 ? 1 : 2;
    }
    r2--;
}

void sol() {
    cin >> n;
    r1 = n * n / 2, r2 = n * n - r1;
    X1 = 1;
    Y1 = 2;
    X2 = 1;
    Y2 = 1;
    for (int i = 0; i < n * n; i++) {
        int u;
        cin >> u;
        if (u == 1) {
            if (r1) {
                R1(2);
            } else {
                R2(3);
            }
        }
        if (u == 2) {
            if (r2) {
                R2(1);
            } else {
                R1(3);
            }
        }
        if (u == 3) {
            if (r1) {
                R1(2);
            } else {
                R2(1);
            }
        }
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