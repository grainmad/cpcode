#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    while (1) {
        int c = ceil(sqrt(n));
        for (int i = c + 1; i < n; i++) {
            ans.emplace_back(i, n);
        }
        ans.emplace_back(n, c);
        ans.emplace_back(n, c);
        n = c;
        if (c == 2)
            break;
    }
    cout << ans.size() << "\n";
    for (auto [i, j] : ans) {
        cout << i << " " << j << "\n";
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