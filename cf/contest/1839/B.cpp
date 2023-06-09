#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        sort(a[i].rbegin(), a[i].rend());
        int sz = a[i].size();
        ans += accumulate(a[i].begin(), a[i].begin() + min(sz, i), 0LL);
    }
    cout << ans << "\n";
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