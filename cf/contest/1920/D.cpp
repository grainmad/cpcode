#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

const ll MX = 1000000000000000007LL;

void sol() {
    int n, q;
    cin >> n >> q;
    vector<pair<ll, ll>> a;
    vector<pair<ll, __int128_t>> op2;  // index, pre mult
    __int128_t sz = 0;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        if (x == 2)
            y++;
        a.emplace_back(x, y);
        if (sz > MX)
            continue;
        if (x == 1)
            sz += 1;
        if (x == 2) {
            op2.emplace_back(i, sz);
            sz *= y;
        }
    }
    // for (auto [i, j] : op2) {
    //     cout << i << " " << j << endl;
    // }
    a.emplace_back(2, 1);
    op2.emplace_back(n, sz);  // 哨兵
    function<ll(ll)> getval = [&](ll x) {
        // if (x == 1)
        //     return a[0].second;
        for (auto [i, j] : op2) {
            if (j < x && x <= j * a[i].second) {
                ll r = x % j;
                if (r == 0)
                    r = j;
                return getval(r);
            }
            if (x <= j) {
                // cout << i << " " << j << " " << x << endl;
                return a[i - (j - x) - 1].second;
            }
        }
        return -1LL;
    };
    while (q--) {
        ll w;
        cin >> w;
        cout << getval(w) << " ";
    }
    cout << "\n";
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