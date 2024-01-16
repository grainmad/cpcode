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
    string a, b;
    cin >> a >> b;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1' && b[i] == '0')
            x++;
        if (a[i] == '0' && b[i] == '1')
            y++;
    }
    cout << max(y, x) << "\n";
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