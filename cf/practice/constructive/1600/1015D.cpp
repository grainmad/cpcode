#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, k, s;
    cin >> n >> k >> s;
    if ((n - 1) * k < s || k > s) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    ll p = 1;
    for (int i = 0; i < k; i++) {
        if (i % 2 == 0) {
            p += s / k + (i < s % k ? 1 : 0);
        } else {
            p -= s / k + (i < s % k ? 1 : 0);
        }
        cout << p << " ";
    }
    cout << "\n";
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