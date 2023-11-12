#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    auto check = [](int x) {
        int t = x % 10;
        int ok = 1;
        for (int k = x; k > 0; k /= 10) {
            if (k % 10 != t)
                ok = 0;
        }
        if (ok)
            return t;
        else
            return -1;
    };
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int d;
        cin >> d;
        int t = check(i);
        if (t == -1)
            continue;
        for (int j = 1; j <= d; j++) {
            if (check(j) == t) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
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