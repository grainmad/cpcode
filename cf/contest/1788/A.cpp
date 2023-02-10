#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 10005
#define MOD 998244353
using namespace std;

int a[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int c = count(a + 1, a + n + 1, 2);
    if (c % 2) {
        cout << "-1\n";
        return;
    }
    for (int i = 1, p = 0; i <= n; i++) {
        p += a[i] == 2;
        if (p == c / 2) {
            cout << i << "\n";
            return;
        }
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