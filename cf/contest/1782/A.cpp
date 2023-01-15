#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int w, d, h;
    cin >> w >> d >> h;
    int a, b, f, g;
    cin >> a >> b >> f >> g;
    cout << h + abs(a - f) + abs(b - g) +
                min({a, w - a, b, d - b, f, w - f, g, d - g})*2
         << "\n";
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