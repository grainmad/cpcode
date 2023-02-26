#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    if (n < 26) {
        for (char i = 'a'; i < n + 'a'; i++) {
            cout << i;
        }
        cout << "\n";
    } else {
        if (n % 2) {
            cout << string((n - 2) / 2, 'a') << "bc"
                 << string(n - 2 - (n - 2) / 2, 'a') << "\n";
        } else {
            cout << string((n - 1) / 2, 'a') << "b"
                 << string(n - 1 - (n - 1) / 2, 'a') << "\n";
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