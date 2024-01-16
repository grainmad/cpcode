#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, f, a, b;
    cin >> n >> f >> a >> b;
    ll p = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        cnt += min((x - p) * a, b);
        p = x;
    }
    cout << (cnt < f ? "YES\n" : "NO\n");
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