
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m, p;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == m)
            p = i;
    }
    vector<int> d(n);
    for (int i = p - 1; i >= 0; i--) {
        d[i] += d[i + 1];
        if (a[i] > m)
            d[i]++;
        else if (a[i] < m)
            d[i]--;
    }
    for (int i = p + 1; i < n; i++) {
        d[i] += d[i - 1];
        if (a[i] > m)
            d[i]++;
        else if (a[i] < m)
            d[i]--;
    }
    // for (auto i : d) {
    //     cout << i << " ";
    // }
    map<int, int> mp;
    for (int i = 0; i <= p; i++)
        mp[d[i]]++;
    ll ans = 0;
    for (int i = p; i < n; i++) {
        // d[i] + x = 0 or 1
        ans += mp[-d[i]] + mp[1 - d[i]];
    }
    cout << ans << "\n";
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
