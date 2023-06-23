#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    for (auto& [i, j] : v)
        cin >> i >> j;
    int q;
    cin >> q;
    vector<int> opt(q);
    for (auto& i : opt)
        cin >> i;
    int l = 0, r = q + 1;
    while (l < r) {
        int c = l + r >> 1;
        vector<int> a(n + 1);
        for (int i = 0; i < c; i++)
            a[opt[i]] = 1;
        for (int i = 1; i <= n; i++)
            a[i] += a[i - 1];
        int ok = 0;
        for (auto& [i, j] : v) {
            if (a[j] - a[i - 1] > (j - i + 1) / 2)
                ok = 1;
        }
        if (ok) {
            r = c;
        } else {
            l = c + 1;
        }
    }
    if (r == q + 1) {
        cout << "-1\n";
    } else {
        cout << r << "\n";
    }
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