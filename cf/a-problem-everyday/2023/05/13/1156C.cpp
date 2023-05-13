
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, z;
    cin >> n >> z;
    vector<ll> a(n);
    for (ll& i : a)
        cin >> i;
    sort(a.begin(), a.end());
    auto check = [&](int x) {
        for (int i = 0; i < x; i++) {
            if (a[n - x + i] - a[i] < z)
                return false;
        }
        return true;
    };
    int l = 1, r = n / 2 + 1;
    while (l < r) {
        // cout << l << " " << r << endl;
        int m = l + r >> 1;
        if (check(m)) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << r - 1 << "\n";
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
