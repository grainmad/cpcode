
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, d, m;
    cin >> n >> d >> m;
    vector<ll> x, y;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        (t > m ? y : x).push_back(t);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll xsz = x.size(), ysz = y.size();
    vector<ll> px(xsz, -1);
    function<ll(int)> pre = [&](int u) -> ll {
        if (u < 0)
            return 0;
        if (px[u] != -1)
            return px[u];
        return px[u] = pre(u - 1) + x[u];
    };
    ll b = (ysz + d) / (d + 1);
    ll s = 0;
    for (int i = 0; i < b; i++) {
        s += y.back();
        y.pop_back();
    }
    ll ans = pre(xsz - 1) + s;
    while (y.size()) {
        s += y.back();
        b++;
        y.pop_back();
        ll r = (b - 1) * d - y.size();
        if (r <= xsz) {
            ans = max(ans, pre(xsz - 1) - pre(r - 1) + s);
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
