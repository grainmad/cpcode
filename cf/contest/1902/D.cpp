#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

int dx[256], dy[256];

void sol() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = "#" + s;
    vector<int> vx(n + 1), vy(n + 1);
    map<pair<int, int>, vector<int>> mp;
    mp[{0, 0}].push_back(0);
    for (int i = 1; i <= n; i++) {
        vx[i] = vx[i - 1] + dx[s[i]];
        vy[i] = vy[i - 1] + dy[s[i]];
        mp[{vx[i], vy[i]}].push_back(i);
    }
    while (q--) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        int mx = vx[l - 1] + vx[r] - x, my = vy[l - 1] + vy[r] - y;
        int ok = 0;
        if (mp.count({x, y})) {
            auto& v = mp[{x, y}];
            if (v[0] < l || v.back() >= r)
                ok = 1;
        }
        if (mp.count({mx, my})) {
            auto& v = mp[{mx, my}];
            if (upper_bound(v.begin(), v.end(), r) !=
                lower_bound(v.begin(), v.end(), l))
                ok = 1;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}

int main() {
    dx['U'] = 0, dy['U'] = 1;
    dx['D'] = 0, dy['D'] = -1;
    dx['L'] = -1, dy['L'] = 0;
    dx['R'] = 1, dy['R'] = 0;
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