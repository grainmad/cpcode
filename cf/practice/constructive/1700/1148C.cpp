#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll a[N], p[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++) {
        if (p[i] == i)
            continue;
        if (2 * (p[i] - i) >= n) {
            swap(a[i], a[p[i]]);
            ans.emplace_back(i, p[i]);
        } else if (i <= n / 2 && p[i] <= n / 2) {
            swap(a[i], a[n]);
            swap(a[p[i]], a[n]);
            swap(a[i], a[n]);
            ans.emplace_back(i, n);
            ans.emplace_back(p[i], n);
            ans.emplace_back(i, n);
        } else if (i > n / 2 && p[i] > n / 2) {
            swap(a[i], a[1]);
            swap(a[p[i]], a[1]);
            swap(a[i], a[1]);
            ans.emplace_back(i, 1);
            ans.emplace_back(p[i], 1);
            ans.emplace_back(i, 1);
        } else {
            swap(a[i], a[n]);
            swap(a[1], a[n]);
            swap(a[1], a[p[i]]);
            swap(a[1], a[n]);
            swap(a[i], a[n]);
            ans.emplace_back(i, n);
            ans.emplace_back(1, n);
            ans.emplace_back(1, p[i]);
            ans.emplace_back(1, n);
            ans.emplace_back(i, n);
        }
        p[a[p[i]]] = p[i];
        p[i] = i;
        // cout << i << endl;
        // for (int j = 1; j <= n; j++) {
        //     cout << a[j] << " ";
        // }
        // cout << endl;
        // for (int j = 1; j <= n; j++) {
        //     cout << j << "=" << p[j] << " ";
        // }
        // cout << endl;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << i << "=" << p[i] << " ";
    // }
    // cout << endl;
    cout << ans.size() << "\n";
    for (auto& [x, y] : ans) {
        cout << x << " " << y << "\n";
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