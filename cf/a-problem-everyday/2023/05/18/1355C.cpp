
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

ll dif[2 * N];

void sol() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    for (ll i = a; i <= b; i++) {
        dif[i + b]++;
        dif[i + c + 1]--;
    }
    ll ans = 0;
    for (ll i = a + b; i <= b + c + 1; i++) {
        dif[i] += dif[i - 1];
        ans += min(max(i - c, 0LL), d - c + 1) * dif[i];
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
