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
    vector<ll> a(n), b(m);
    for (auto& i : a)
        cin >> i;
    for (auto& i : b)
        cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int l1 = 0, r1 = n - 1, l2 = 0, r2 = m - 1;
    ll ans = 0;
    while (l1 <= r1) {
        if (abs(a[l1] - b[r2]) > abs(a[r1] - b[l2])) {
            ans += abs(a[l1] - b[r2]);
            l1++;
            r2--;
        } else {
            ans += abs(a[r1] - b[l2]);
            r1--;
            l2++;
        }
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