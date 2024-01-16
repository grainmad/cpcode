#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int x1 = 1005, x2 = -1005, y1 = 1005, y2 = -1005;
    for (int i = 0; i < 4; i++) {
        int x, y;
        cin >> x >> y;
        x1 = min(x, x1);
        x2 = max(x, x2);
        y1 = min(y, y1);
        y2 = max(y, y2);
    }
    cout << (x2 - x1) * (y2 - y1) << "\n";
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