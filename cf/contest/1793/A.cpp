#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll a, b, n, m;
    cin >> a >> b >> n >> m;
    cout << min((n - n / (m + 1)) * a,
                n / (m + 1) * min(m * a, (m + 1) * b) + n % (m + 1) * b)
         << "\n";
    // if (a <= b) {
    //     cout << n * a - n / (m + 1) * a << "\n";
    // } else if (m * (a - b) < b) {
    //     ll ca = n / (m + 1) * (m + 1), cb = n - ca;
    //     cout << ca * a - ca / (m + 1) * a + cb * b << "\n";
    // } else {
    //     cout << n * b << "\n";
    // }
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