#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, k;
    cin >> n >> k;
    if (k * k - k >= n) {
        cout << "YES\n";
        for (int i = 1; i < k; i++) {
            for (int j = 0; j < k; j++) {
                cout << (i + j) % k + 1 << " " << j + 1 << "\n";
                if (--n == 0)
                    return;
            }
        }
    } else {
        cout << "NO\n";
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