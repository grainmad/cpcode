#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

ll a[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll lev = a[0], opt = 0;
    for (int i = 1; i < n; i++) {
        opt += abs(a[i] - a[i - 1]);
        if (a[i] < a[i - 1])
            lev -= a[i - 1] - a[i];
    }
    cout << opt + abs(lev) << "\n";
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