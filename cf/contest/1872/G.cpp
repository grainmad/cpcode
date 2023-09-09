#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

const ll MX = 2e14 + 5;
ll a[N];

void sol() {
    int n;
    cin >> n;
    ll cur = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (cur < MX / a[i]) {
            cur *= a[i];
        } else {
            int l = 1, r = n;
            while (a[l] == 1)
                l++;
            while (a[r] == 1)
                r--;
            cout << l << " " << r << "\n";
            return;
        }
    }
    vector<ll> prf(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++) {
        prf[i] = prf[i - 1] + a[i];
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + a[i];
    }
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (a[i] != 1) {
            v.push_back(i);
        }
    }
    ll ans = a[1], l = 1, r = 1;
    int sz = v.size();
    for (int i = 0; i < sz; i++) {
        for (int j = i; j < sz; j++) {
            ll tans = prf[v[i] - 1] + suf[v[j] + 1], mult = 1;
            for (int k = i; k <= j; k++) {
                mult *= a[v[k]];
            }
            if (tans + mult > ans) {
                ans = tans + mult;
                l = v[i], r = v[j];
            }
        }
    }
    cout << l << " " << r << "\n";
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