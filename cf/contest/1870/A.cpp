#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k, x;
    cin >> n >> k >> x;
    if (k > n || x + 1 < k) {
        cout << "-1\n";
    } else {
        cout << (k - 1) * k / 2 + (k == x ? x - 1 : x) * (n - k) << endl;
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