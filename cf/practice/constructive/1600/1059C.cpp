#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    int p = 1;
    while (n > 3) {
        for (int i = 0; i < n - n / 2; i++) {
            cout << p << " ";
        }
        p <<= 1;
        n = n / 2;
    }
    for (int i = 1; i < n; i++) {
        cout << p << " ";
    }
    cout << p * n << "\n";
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