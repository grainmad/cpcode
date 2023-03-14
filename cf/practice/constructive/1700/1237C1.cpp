#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll dis(vector<ll>& a, vector<ll>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]) + abs(a[2] - b[2]);
}

void sol() {
    int n;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(3));
    for (auto& i : v) {
        for (auto& j : i)
            cin >> j;
    }
    vector<int> vis(n);
    for (int i = 0; i < n; i++) {
        if (vis[i])
            continue;
        ll mn = 1e18, p = i + 1;
        for (int j = i + 1; j < n; j++) {
            if (vis[j])
                continue;
            ll d = dis(v[i], v[j]);
            if (mn > d) {
                mn = d;
                p = j;
            }
        }
        vis[i] = vis[p] = 1;
        cout << i + 1 << " " << p + 1 << "\n";
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