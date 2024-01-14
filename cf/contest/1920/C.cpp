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
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    auto check = [&](int x) {
        int gc = 0;
        for (int i = 0; i < x; i++) {
            int g = 0, c = 1, mn = a[i];
            for (int j = i; j < n; j += x) {
                mn = min(mn, a[j]);
            }
            for (int j = i; j < n; j += x) {
                if (a[j] != a[i])
                    c = 0;
                g = gcd(g, a[j] - mn);
            }
            if (c)
                continue;
            gc = gcd(gc, g);
        }
        if (gc != 1)
            return 1;
        return 0;
    };
    int ans = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i)
            continue;
        ans += check(i);
        if (n / i != i)
            ans += check(n / i);
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