#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

// ll ta[N] = {0, 5, 3, 1, 4, 7};

ll a[N];

ll sum(ll x, ll y) {
    ll u, v;
    cout << "and " << x << " " << y << endl;
    cin >> u;
    // u = ta[x] & ta[y];
    cout << "or " << x << " " << y << endl;
    cin >> v;
    // v = ta[x] | ta[y];
    return v + u;
}

void sol() {
    int n, k;
    // n = 5, k = 3;
    cin >> n >> k;
    ll x = sum(1, 2), y = sum(2, 3), z = sum(1, 3);
    a[2] = (x + y - z) / 2;
    a[1] = x - a[2];
    a[3] = y - a[2];
    for (int i = 4; i <= n; i++) {
        a[i] = sum(i - 1, i) - a[i - 1];
    }
    sort(a + 1, a + n + 1);
    cout << "finish " << a[k] << endl;
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