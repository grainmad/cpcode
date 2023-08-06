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
    vector<ll> a(n);
    for (auto& i : a)
        cin >> i;
    sort(a.begin(), a.end());
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        if (i < sum % n)
            b[i] = 1;
        b[i] += sum / n;
    }
    reverse(b.begin(), b.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max(0LL, a[i] - b[i]);
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