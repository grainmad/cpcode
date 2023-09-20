#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), l(k + 1), r(k + 1), c(k + 1);
    for (auto& i : a)
        cin >> i, c[i] = 1;
    int pl = 1, pr = 1;
    for (int i = 0; i < n; i++) {
        while (pl <= a[i])
            l[pl++] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        while (pr <= a[i])
            r[pr++] = i;
    }
    for (int i = 1; i <= k; i++) {
        if (c[i]) {
            cout << (r[i] - l[i] + 1) * 2 << " ";
        } else {
            cout << "0 ";
        }
    }
    cout << "\n";
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