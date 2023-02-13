#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> p(n), q(n), wp(n + 1), wq(n + 1);
    vector<pair<int, int>> a, b;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        wp[p[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
        wq[q[i]] = i;
    }
    ll l1 = min(wp[1], wq[1]), r1 = max(wp[1], wq[1]);
    auto cpt = [](ll x) -> ll { return x * (x + 1) / 2; };
    ll ans = cpt(l1) + cpt(n - r1 - 1) + cpt(max(r1 - l1 - 1, 0LL)) + 1;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            a.emplace_back(wp[i], wp[i]);
            b.emplace_back(wq[i], wq[i]);
        } else {
            auto [x1, y1] = a.back();
            a.emplace_back(min(x1, wp[i]), max(y1, wp[i]));
            auto [x2, y2] = b.back();
            b.emplace_back(min(x2, wq[i]), max(y2, wq[i]));
        }
    }
    for (int i = 1; i < n; i++) {
        // auto [x1, y1] = a[i - 1];
        // auto [x2, y2] = a[i];
        // auto [x3, y3] = b[i - 1];
        // auto [x4, y4] = b[i];
        int la = a[i - 1].first, ra = a[i - 1].second;
        int lla = a[i].first, rra = a[i].second;
        if (lla < la) {
            // lla++;
            // rra = n - 1;
            rra = n;
        } else {
            // rra--;
            // lla = 0;
            lla = -1;
        }
        int lb = b[i - 1].first, rb = b[i - 1].second;
        int llb = b[i].first, rrb = b[i].second;
        if (llb < lb) {
            // llb++;
            // rrb = n - 1;
            rrb = n;
        } else {
            // rrb--;
            // llb = 0;
            llb = -1;
        }
        ll lcnt = max(0, min(la, lb) - max(lla, llb));
        ll rcnt = max(0, min(rra, rrb) - max(ra, rb));
        ans += lcnt * rcnt;
    }
    cout << ans << endl;
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