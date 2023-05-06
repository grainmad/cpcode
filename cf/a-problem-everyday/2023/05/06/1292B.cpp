
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
	ll x0, y0, ax, ay, bx, by, xs, ys, t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
    vector<pair<ll,ll>> p;
    ll cx = x0, cy = y0;
    while (cx<=xs+t && cy<=ys+t) {
        p.emplace_back(cx, cy);
        cx = cx*ax+bx;
        cy = cy*ay+by;
    }
    ll ans = 0;
    for (int i=0; i<p.size(); i++) {
        ll px = xs, py = ys, d = 0, tans = 0;
        for (int j=i; j<p.size(); j++) {
            ll x = p[j].first, y = p[j].second;
            d += abs(px-x)+abs(py-y);
            if (d<=t) tans++;
            else break;
            px = x, py = y;
        }
        ans = max(ans, tans);
    }
    for (int i=0; i<p.size(); i++) {
        ll px = xs, py = ys, d = 0, tans = 0;
        for (int j=i; j>=0; j--) {
            ll x = p[j].first, y = p[j].second;
            d += abs(px-x)+abs(py-y);
            if (d<=t) tans++;
            else break;
            px = x, py = y;
        }
        ans = max(ans, tans);
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
