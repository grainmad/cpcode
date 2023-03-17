#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll a[N];

void sol() {
    int n, k, d, w;
    cin >> n >> k >> d >> w;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int p = 0, t = a[0], i = 0, ans = 0;
    while (i < n) {
        while (i - p + 1 <= k && a[i] - t <= w + d)
            i++;
        p = i;
        t = a[i];
        ans++;
    }
    cout << ans << "\n";
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