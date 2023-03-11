#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    int p = 0, u = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            u++;
        } else {
            ans = max(ans, (p ? p / 2 + 1 : 0) + u);
            p += u;
            u = 0;
        }
    }
    if (u) {
        ans = max(ans, (p ? p / 2 + 1 : 0) + u);
    }
    cout << ans << "\n";
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