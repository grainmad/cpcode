#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, m, k;
    cin >> n >> m >> k;
    if (k > 3) {
        cout << "0\n";
    } else if (k == 3) {
        if (m <= n)
            cout << "0\n";
        else
            cout << (m - n - (m - n) / n) << "\n";
    } else if (k == 2) {
        if (m > n)
            cout << (n + (m - n) / n) << "\n";
        else
            cout << m << "\n";
    } else {
        cout << "1\n";
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