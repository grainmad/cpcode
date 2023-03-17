#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m, p;
    cin >> n >> m >> p;
    int a = n, b = m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % p)
            a = min(a, i);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (x % p)
            b = min(b, i);
    }
    cout << a + b << endl;
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