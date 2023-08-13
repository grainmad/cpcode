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
    vector<vector<int>> a(n);
    ll s = 0, mn1 = 1e10, mn2 = 1e10;
    for (int i = 0; i < n; i++) {
        int c, x;
        cin >> c;
        for (int j = 0; j < c; j++) {
            cin >> x;
            a[i].push_back(x);
        }
        sort(a[i].begin(), a[i].end());
        mn1 = min(1LL * a[i][0], mn1);
        mn2 = min(1LL * a[i][1], mn2);
        s += a[i][1];
    }
    cout << s - mn2 + mn1 << "\n";
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