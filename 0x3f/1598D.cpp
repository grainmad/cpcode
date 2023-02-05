#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

int a[N], b[N];

void sol() {
    ll n;
    cin >> n;
    map<int, ll> x, y;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        x[a[i]]++;
        y[b[i]]++;
    }
    ll ex = 0;
    for (int i = 0; i < n; i++) {
        ex += (x[a[i]] - 1) * (y[b[i]] - 1);
    }
    cout << n * (n - 1) * (n - 2) / 6 - ex << "\n";
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