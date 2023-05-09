
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 1000000007
using namespace std;

ll fpow(ll x, ll y) {
    ll rt = 1;
    while (y) {
        if (y & 1) {
            rt = rt * x % MOD;
        }
        x = x * x % MOD;
        y >>= 1;
    }
    return rt;
}

void sol() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    ll s = 0;
    for (ll& i : a)
        cin >> i, s += i;
    for (ll& i : a)
        i = s - i;
    sort(a.rbegin(), a.rend());
    while (1) {
        ll c = 0, v = a.back();
        while (a.size() && v == a.back())
            a.pop_back(), c++;
        if (c % x == 0) {
            c /= x;
            for (int i = 0; i < c; i++) {
                a.push_back(v + 1);
            }
        } else {
            v = min(v, s);
            cout << fpow(x, v) << "\n";
            return;
        }
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
