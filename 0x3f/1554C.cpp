#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, m;
    cin >> n >> m;
    if (n > m) {
        cout << 0 << "\n";
        return;
    }
    m++;
    ll ans = 0;
    for (int i = 32; i >= 0; i--) {
        if ((n >> i & 1) == 0 && (m >> i & 1) == 1) {
            ans |= 1 << i;
            if ((ans | n) > m) {
                cout << ans << "\n";
                return;
            }
        }
    }
    cout << ans << "\n";
    // ll ans = 0;  // find ans make ans^n > m
    // for (int i = 32; i >= 0; i--) {
    //     if ((n >> i & 1) == 0 && (m >> i & 1) == 1) {
    //         ans |= 1 << i;
    //         if ((ans | n) > m) {
    //             cout << ans << "\n";
    //             return;
    //         }
    //     }
    // }
    // // n in m， ans^n == m
    // ll x = (m + 1) & -(m + 1);
    // ans |= x - 1;
    // ans ^= x - 1;
    // ans |= x;
    // cout << ans << endl;
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

// 00011110001001000000
// 10011111101111110001

// 10000001100110110010