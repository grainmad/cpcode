#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    priority_queue<vector<int>> q;
    q.push({n, -1, n});
    for (int i = 1; i <= n; i++) {
        auto u = q.top();
        q.pop();
        int l = -u[1], r = u[2];
        int m = (l + r) / 2;
        a[m] = i;
        if (l <= m - 1)
            q.push({m - l, -l, m - 1});
        if (m + 1 <= r)
            q.push({r - m, -m - 1, r});
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
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