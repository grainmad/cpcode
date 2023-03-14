#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k;
    string a, b;
    cin >> n >> k;
    cin >> a;
    b = a;
    for (int i = 0; i < k; i++) {
        for (int j = i; j < n; j += k) {
            b[j] = a[i];
        }
    }
    if (a <= b) {
        cout << n << "\n";
        cout << b << "\n";
        return;
    }
    for (int i = k - 1; i >= 0; i--) {
        if (b[i] != '9') {
            for (int j = i; j < n; j += k) {
                b[j]++;
            }
            cout << n << "\n";
            cout << b << "\n";
            return;
        } else {
            for (int j = i; j < n; j += k) {
                b[j] = '0';
            }
        }
    }
    // cout << n + 1 << "\n";
    // cout << "1" << b << "\n";
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