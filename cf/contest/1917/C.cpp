#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n + 1), v(k);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    for (auto& i : v)
        cin >> i;
    ll ans = count(a.begin() + 1, a.end(), 0) + (d - 1) / 2;
    // cout << n << " --- " << endl;
    // cout << count(a.begin() + 1, a.end(), 0) << endl;
    for (int i = 0; i < 2 * max(k, n); i++) {
        for (int j = 1; j <= v[i % k]; j++) {
            a[j]++;
        }
        if (d - 2 - i >= 0)
            ans = max(ans, count(a.begin() + 1, a.end(), 0) + (d - 2 - i) / 2);
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