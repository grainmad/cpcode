
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<ll, ll>> v(1, {0, 0});
    ll x = 0, y = 0;
    for (auto i : s) {
        if (i == 'U') {
            y++;
        }
        if (i == 'D') {
            y--;
        }
        if (i == 'L') {
            x--;
        }
        if (i == 'R') {
            x++;
        }
        v.emplace_back(x, y);
    }
    ll l = 0, r = 1e18 + 7;
    while (l < r) {
        ll m = l + r >> 1;
        ll K = m / n, R = m % n;
        ll cx = x1 + K * x + v[R].first, cy = y1 + K * y + v[R].second;
        if (abs(x2 - cx) + abs(y2 - cy) <= m) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if (r == 1e18 + 7) {
        cout << "-1\n";
    } else {
        cout << r << "\n";
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
