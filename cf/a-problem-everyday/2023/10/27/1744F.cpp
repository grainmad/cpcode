
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }
    int l = p[0], r = p[0];  // l和r为mex为i，0到i-1中最小位置和最大位置。
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        // 包含了0...i-1，mex至少为i，需要med<i，则长度为2*i以内包含l和r的区间
        if (p[i] < l) {
            for (int j = l; j > p[i]; j--) {
                // 右端最远min(j+2*i-1, n-1);
                ans += max(min(j + 2 * i - 1, n - 1) - r + 1,
                           0);  // 右端能选择的位置个数。
            }
            l = p[i];
        } else if (p[i] > r) {
            for (int j = r; j < p[i]; j++) {
                // 左端最远 max(j-2*i+1, 0)
                ans += max(l - max(j - 2 * i + 1, 0) + 1, 0);
            }
            r = p[i];
        }
    }
    // 当mex至少为n时，包含了所有数，所以l=0，r=n-1，所以还有贡献1.
    cout << ans + 1 << "\n";
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
