#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<ll> a(n), p1(n), p2(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        p1[i] += p1[i - 1];
        if (i >= 2 && a[i] - a[i - 1] > a[i - 1] - a[i - 2]) {
            p1[i] += a[i] - a[i - 1];
        } else {
            p1[i]++;
        }
    }
    reverse(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        p2[i] += p2[i - 1];
        if (i >= 2 && abs(a[i] - a[i - 1]) > abs(a[i - 1] - a[i - 2])) {
            p2[i] += abs(a[i] - a[i - 1]);
        } else {
            p2[i]++;
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << i << " " << p1[i] << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << i << " " << p2[i] << endl;
    // }
    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (x > y) {
            x = n - x;
            y = n - y;
            cout << p2[y] - p2[x] << "\n";
        } else {
            x--;
            y--;
            cout << p1[y] - p1[x] << "\n";
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