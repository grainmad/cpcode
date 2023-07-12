#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll& i : a)
        cin >> i;
    if (count_if(a.begin(), a.end(), [&](ll x) { return x < 0; }) == n) {
        cout << *max_element(a.begin(), a.end()) << "\n";
    } else {
        ll ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2)
                ans1 += max(0LL, a[i]);
            else
                ans2 += max(0LL, a[i]);
        }
        cout << max(ans1, ans2) << "\n";
    }
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