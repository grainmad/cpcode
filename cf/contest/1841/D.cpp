#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define INF 0x3f3f3f3f
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto& [i, j] : a)
        cin >> i >> j;
    sort(a.begin(), a.end(), [&](auto& x, auto& y) {
        if (x.second == y.second)
            return x.first < y.first;
        return x.second < y.second;
    });
    // for (auto [i, j] : a) {
    //     cout << i << " " << j << endl;
    // }
    vector<int> f(n, n);
    f[0] = 1;
    for (int i = 1; i < n; i++) {
        f[i] = f[i - 1] + 1;
        for (int j = i - 1; j >= 0 && a[j].second >= a[i].first; j--) {
            int l = 0, r = j;
            while (l < r) {
                int m = l + r >> 1;
                if (a[m].second < min(a[j].first, a[i].first)) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            if (r - 1 >= 0)
                f[i] = min(f[i], f[r - 1] + i - r - 1);  // i-r+1个中留两个
            else
                f[i] = min(f[i], i - 1);
        }
        // cout << i << " " << f[i] << "\n";
    }
    cout << f[n - 1] << "\n";
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