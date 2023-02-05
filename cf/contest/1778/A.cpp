#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

int a[N];

void sol() {
    int n, s = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    int mx = -N;
    for (int i = 1; i < n; i++) {
        mx = max(mx, s - 2 * a[i - 1] - 2 * a[i]);
    }
    cout << mx << "\n";
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