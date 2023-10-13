#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    vector<ll> a(3);
    for (ll& i : a)
        cin >> i;
    sort(a.begin(), a.end());
    if (a[0] == a[1] && a[1] == a[2] || a[0] == a[1] && a[1] * 2 == a[2] ||
        a[0] * 2 == a[1] && a[1] == a[2] || a[0] == a[1] && a[1] * 3 == a[2] ||
        a[0] * 2 == a[1] && a[0] * 3 == a[2] ||
        a[0] == a[1] && a[0] * 4 == a[2]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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