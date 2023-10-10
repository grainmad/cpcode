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
    auto check = [](ll x, ll y, ll z) {
        if (x == y || x == z || y == z)
            return false;
        if (x % 3 == 0 || y % 3 == 0 || z % 3 == 0)
            return false;
        if (x <= 0 || y <= 0 || z <= 0)
            return false;
        return true;
    };
    if (n % 3 == 0) {
        if (check(1, 4, n - 5)) {
            cout << "YES\n";
            cout << "1 4 " << n - 5 << "\n";
        } else {
            cout << "NO\n";
        }

    } else if (n % 3 == 1) {
        if (check(1, 2, n - 3)) {
            cout << "YES\n";
            cout << "1 2 " << n - 3 << "\n";
        } else {
            cout << "NO\n";
        }
    } else {
        if (check(1, 2, n - 3)) {
            cout << "YES\n";
            cout << "1 2 " << n - 3 << "\n";
        } else {
            cout << "NO\n";
        }
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