#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k;
    cin >> n >> k;
    cout << "YES\n";
    vector<string> ans(4, string(n, '.'));
    for (int i = 0; i < (k + 1) / 2 - 1; i++) {
        ans[i % 2 + 1][i / 2 + 1] = ans[(i % 2 + 1)][n - 1 - (i / 2 + 1)] = '#';
    }
    if (k > 0) {
        if (k % 2 == 0)
            ans[1][n / 2] = '#';
        ans[2][n / 2] = '#';
    }
    for (int i = 0; i < 4; i++) {
        cout << ans[i] << "\n";
    }
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