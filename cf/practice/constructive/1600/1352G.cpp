#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    if (n < 4) {
        cout << "-1\n";
        return;
    }
    for (int i = n % 2 ? n : n - 1; i >= 1; i -= 2) {
        cout << i << " ";
    }
    cout << "4 2 ";
    for (int i = 6; i <= n; i += 2) {
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