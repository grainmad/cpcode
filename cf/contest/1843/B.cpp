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
    int f = 0, cnt = 0;
    ll ans = 0;
    for (int i : a) {
        if (i < 0 && !f) {
            f = 1;
            cnt++;
        } else if (i > 0 && f) {
            f = 0;
        }
        ans += abs(i);
    }
    cout << ans << " " << cnt << "\n";
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