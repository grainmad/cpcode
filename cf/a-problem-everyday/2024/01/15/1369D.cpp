
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 2000005
#define MOD 1000000007
using namespace std;

ll f[N];

void sol() {
    int n;
    cin >> n;
    cout << f[n] << "\n";
}

int main() {
    // f[1] = f[2] = 0;
    // f[3] = f[4] = 4;
    // for (int i = 5; i < N; i++) {
    //     f[i] = max((f[i - 1] + f[i - 2] * 2) % MOD,
    //                (f[i - 2] + f[i - 3] * 4 + f[i - 4] * 4 + 4) % MOD);
    // }
    f[1] = f[2] = 0;
    f[3] = f[4] = 4;
    for (int i = 5; i < N; i++) {
        f[i] = f[i - 1] + f[i - 2] * 2 + (i % 3 == 0 ? 4 : 0);
        f[i] %= MOD;
    }
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
