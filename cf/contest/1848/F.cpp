#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a)
        cin >> i;
    int ans = 0;
    auto dfs = [&](auto self, int x) -> int {
        if (x == 1)
            return a[0] != 0;
        int ok = 1;
        for (int i = 0; i < x / 2; i++) {
            if (a[i] != a[i + x / 2])
                ok = 0;
        }
        if (ok)
            return self(self, x / 2);
        for (int i = 0; i < x / 2; i++) {
            a[i] ^= a[i + x / 2];
        }
        return self(self, x / 2) + x / 2;
    };
    cout << dfs(dfs, n) << endl;
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