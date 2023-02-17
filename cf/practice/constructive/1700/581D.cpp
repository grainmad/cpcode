#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 505
#define MOD 998244353
using namespace std;

int x[3], y[3], mx = 0, s = 0;

void Case(int a, int b, int c) {
    for (int i = 0; i < y[a]; i++) {
        cout << string(x[a], 'A' + a) << "\n";
    }
    if (x[a] == x[b] && x[a] == x[c]) {
        for (int i = 0; i < y[b]; i++) {
            cout << string(x[a], 'A' + b) << "\n";
        }
        for (int i = 0; i < y[c]; i++) {
            cout << string(x[a], 'A' + c) << "\n";
        }
    } else {
        if (x[b] + y[a] != mx)
            swap(x[b], y[b]);
        if (x[c] + y[a] != mx)
            swap(x[c], y[c]);
        for (int i = 0; i < x[b]; i++) {
            cout << string(y[b], 'A' + b) + string(y[c], 'A' + c) << "\n";
        }
    }
}

void sol() {
    for (int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
        mx = max({mx, x[i], y[i]});
        if (x[i] < y[i])
            swap(x[i], y[i]);
        s += x[i] * y[i];
    }
    if (s != mx * mx) {
        cout << "-1\n";
        return;
    }
    cout << mx << "\n";
    if (x[0] == mx) {
        Case(0, 1, 2);
    } else if (x[1] == mx) {
        Case(1, 2, 0);
    } else {
        Case(2, 0, 1);
    }
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
