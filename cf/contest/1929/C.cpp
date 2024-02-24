#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll k, x, a;
    cin >> k >> x >> a;
    ll b = a;
    int ok = 1;
    for (int i = 1; i <= x; i++) {
        ll bet = (b - a + k - 2) / (k - 1);
        while (bet <= a && bet * (k - 1) + a <= b)
            bet++;
        if (a < bet) {
            ok = 0;
            break;
        }
        a -= bet;
        // cout << bet << " " << a << endl;
        // if (bet * k + a <= b) {
        //     cout << "o" << endl;
        // }
    }
    if (a * k <= b)
        ok = 0;
    cout << (ok ? "YES\n" : "NO\n");
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