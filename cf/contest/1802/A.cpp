#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x > 0)
            a++;
        if (x < 0)
            b++;
    }
    for (int i = 1; i <= a; i++) {
        cout << i << " ";
    }
    for (int i = 1; i <= b; i++) {
        cout << a - i << " ";
    }
    cout << "\n";
    for (int i = 0; i < b; i++) {
        cout << "1 0 ";
    }
    for (int i = 1; i <= a - b; i++) {
        cout << i << " ";
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