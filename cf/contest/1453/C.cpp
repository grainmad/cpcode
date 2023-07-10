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
    vector<string> g(n);
    for (auto& i : g) {
        cin >> i;
    }
    vector<ll> ans(10), mxr(10, -1), mnr(10, 2005), mxc(10, -1), mnc(10, 2005);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            int num = g[i][j] - '0';
            mxr[num] = max(mxr[num], i);
            mnr[num] = min(mnr[num], i);
            mxc[num] = max(mxc[num], j);
            mnc[num] = min(mnc[num], j);
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            int num = g[i][j] - '0';
            ll r = max(n - i - 1, i);
            ll c = max(n - j - 1, j);
            ans[num] = max(ans[num], r * max(mxc[num] - j, j - mnc[num]));
            ans[num] = max(ans[num], c * max(mxr[num] - i, i - mnr[num]));
        }
    }
    for (ll i : ans) {
        cout << i << " ";
    }
    cout << "\n";
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