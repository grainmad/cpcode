
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int s, x1, x2, t1, t2, p, d;
    cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
    int a = abs(x2 - x1) * t2;
    if (t1 > t2) {
        cout << a << "\n";
        return;
    }
    if (x1 < x2) {
        // if (p <= x1) {
        //     if (d == 1) {
        //         a = min(a, (x2 - p) * t1);
        //     } else {
        //         a = min(a, (p + x2) * t1);
        //     }
        // } else {
        //     if (d == 1) {
        //         a = min(a, (s-p+s+x2)*t1);
        //     } else {
        //         a = min(a, (p+x2)*t1);
        //     }
        // }
        if (d == 1) {
            if (p <= x1) {
                a = min(a, (x2 - p) * t1);
            } else {
                a = min(a, (s - p + s + x2) * t1);
            }
        } else {
            a = min(a, (p + x2) * t1);
        }

    } else {
        // if (p >= x1) {
        //     if (d == -1) {
        //         a = min(a, (p - x2) * t1);
        //     } else {
        //         a = min(a, (s-p + s-x2) * t1);
        //     }
        // } else {
        //     if (d == -1) {
        //         a = min(a, (p+s+s-x2)*t1);
        //     } else {
        //         a = min(a, (s-p+s-x2)*t1);
        //     }
        // }
        if (d == -1) {
            if (p >= x1) {
                a = min(a, (p - x2) * t1);
            } else {
                a = min(a, (p + s + s - x2) * t1);
            }
        } else {
            a = min(a, (s - p + s - x2) * t1);
        }
    }
    cout << a << "\n";
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
