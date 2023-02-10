#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    if ((3 + 3 * n) % 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int s = (3 + 3 * n) / 2;
    for (int i = 2; i <= n; i += 2) {
        cout << i << " " << s - i << "\n";
        s++;
    }
    for (int i = 1; i <= n; i += 2) {
        cout << i << " " << s - i << "\n";
        s++;
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