
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i % 2) {
            p[i] = p[i - 1] + (s[i - 1] == '+' ? 1 : -1);
        } else {
            p[i] = p[i - 1] - (s[i - 1] == '+' ? 1 : -1);
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (p[y] - p[x - 1] == 0) {
            cout << "0\n";
        } else {
            cout << ((y - x + 1) % 2 ? 1 : 2) << "\n";
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
