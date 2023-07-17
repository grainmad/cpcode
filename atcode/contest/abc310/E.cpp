#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll o = 0, z = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        ll co, cz;
        if (s[i] == '1') {
            co = z;
            cz = o;
            co++;
        } else {
            co = o + z;
            cz = 1;
        }
        o = co;
        z = cz;
        ans += o;
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