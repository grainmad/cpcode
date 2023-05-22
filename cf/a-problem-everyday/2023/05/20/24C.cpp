
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 200005
#define MOD 998244353
using namespace std;

int mx[N], my[N], ax[N], ay[N];

void sol() {
    ll n, j;
    cin >> n >> j;
    cin >> mx[0] >> my[0];
    for (int i = 0; i < n; i++) {
        cin >> ax[i] >> ay[i];
    }
    for (int i = 1; i < 2 * n; i++) {
        mx[i] = 2 * ax[(i - 1) % n] - mx[i - 1];
        my[i] = 2 * ay[(i - 1) % n] - my[i - 1];
    }
    cout << mx[j % (2 * n)] << " " << my[j % (2 * n)] << "\n";
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
