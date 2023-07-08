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
    vector<int> v(256);
    v[0] = 1;
    int ans = 0, p = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p ^= x;
        v[p] = 1;
        for (int j = 0; j < 256; j++) {
            if (v[j])
                ans = max(ans, j ^ p);
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