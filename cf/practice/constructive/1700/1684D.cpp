#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

ll a[N];

void sol() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),
         [&](int x, int y) { return a[x] + x > a[y] + y; });
    ll ans = accumulate(a, a + n, -(k - 1LL) * k / 2);
    for (int i = 0; i < k; i++) {
        int j = idx[i];
        ans -= a[j] - (n - 1 - j);
    }
    cout << ans << endl;
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