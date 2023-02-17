#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(51);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (l <= k && k <= r) {
            for (int i = l; i <= r; i++) {
                a[i]++;
            }
        }
    }
    for (int i = 1; i <= 50; i++) {
        if (i == k)
            continue;
        if (a[i] >= a[k]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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