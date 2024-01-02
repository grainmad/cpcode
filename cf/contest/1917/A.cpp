#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    int neg = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0)
            neg++;
        if (x == 0)
            zero++;
    }
    if (neg % 2 || zero) {
        cout << "0\n";
    } else {
        cout << "1\n1 0\n";
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