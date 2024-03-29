#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& i : a)
        cin >> i;
    ll sum = 0;
    for (int i = 1; i < n; i++)
        sum += abs(a[i] - a[i - 1]);
    ll ans = sum - max(abs(a[0] - a[1]), abs(a[n - 1] - a[n - 2]));
    for (int i = 1; i < n - 1; i++) {
        ans = min(ans, sum - abs(a[i + 1] - a[i]) - abs(a[i] - a[i - 1]) +
                           abs(a[i + 1] - a[i - 1]));
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