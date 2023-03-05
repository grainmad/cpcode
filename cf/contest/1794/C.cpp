#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll a[N], b[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int l = 0, r = i;
        while (l < r) {
            int m = (l + r + 1) >> 1;
            if (a[m] / (i - m + 1)) {
                r = m - 1;
            } else {
                l = m;
            }
        }
        // cout << i << " " << l << endl;
        b[i] = i - l;
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
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