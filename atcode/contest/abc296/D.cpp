#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

/*
min i * ceil(m/i), i in [1, min(n, m)] ceil(m/i) in [1, m]
min i * floor((m+i-1)/i)
*/
const ll INF = 1e15;

void sol() {
    ll n, m;
    cin >> n >> m;
    ll ans = INF;
    ll l = 1, r = 0;
    // while (l <= m) {
    //     r = m / (m / l);
    //     if (l <= n && (m + l - 1) / l <= n)
    //         ans = min(ans, (m + l - 1) / l * l);
    //     l = r + 1;
    // }
    while (l <= m) {
        r = (m + l - 1) / ((m + l - 1) / l);
        if (l <= n && (m + l - 1) / l <= n)
            ans = min(ans, (m + l - 1) / l * l);
        l = r + 1;
    }
    if (ans == INF)
        cout << "-1\n";
    else
        cout << ans << "\n";
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
