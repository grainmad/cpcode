#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i <= n / a; i++) {
        if ((n - i * a) % b == 0) {
            int j = (n - i * a) / b;
            // cout << i << " " << j << " --- \n";
            for (int k = 0; k < i; k++) {
                int add = k * a + 1;
                for (int p = 0; p < a; p++) {
                    cout << (p + 1) % a + add << " ";
                }
            }
            for (int k = 0; k < j; k++) {
                int add = k * b + 1 + i * a;
                for (int p = 0; p < b; p++) {
                    cout << (p + 1) % b + add << " ";
                }
            }
            cout << "\n";
            return;
        }
    }
    cout << "-1\n";
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