#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int a, b;
    cin >> a >> b;
    a = abs(a);
    b = abs(b);
    if (a > b)
        swap(a, b);
    cout << max(0, (b - a) * 2 - 1) + 2 * a << endl;
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