#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& i : a)
        cin >> i;
    int o = 0;
    for (auto& i : b)
        cin >> i, o |= i;
    int x = 0, y = 0;
    for (int i : a) {
        x ^= i | o;
        y ^= i;
    }
    if (n % 2) {
        cout << y << " " << x << "\n";
    } else {
        cout << x << " " << y << "\n";
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