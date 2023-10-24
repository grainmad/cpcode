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
    vector<int> t(24);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        t[y] += x;
    }
    // for (int i = 0; i < 24; i++) {
    //     cout << t[i] << '\n';
    // }
    int sum = 0;
    for (int i = 0; i <= 8; i++) {
        sum += t[i];
    }
    int ans = sum;
    for (int i = 9; i < 2 * 24 - 1; i++) {
        sum -= t[(i - 9) % 24];
        sum += t[i % 24];
        ans = max(ans, sum);
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