#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll x1, y1, x2, y2, x3, y3;
    cin >> x3 >> y3 >> x1 >> y1 >> x2 >> y2;
    auto dis = [](ll x1, ll y1, ll x2, ll y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };
    double d = dis(x1, y1, x2, y2);
    double l = 0, r = 2e4;
    while (r - l > 1e-7) {
        // cout << l << " " << r << endl;
        double m = (l + r) / 2;
        int o1, p1, o2, p2;
        o1 = p1 = o2 = p2 = 0;
        if (dis(x1, y1, 0, 0) <= m)
            o1 = 1;
        if (dis(x1, y1, x3, y3) <= m)
            p1 = 1;
        if (dis(x2, y2, 0, 0) <= m)
            o2 = 1;
        if (dis(x2, y2, x3, y3) <= m)
            p2 = 1;
        if (o1 && p1 || o2 && p2 || m * 2 >= d && (o1 && p2 || o2 && p1))
            r = m;
        else
            l = m;
    }
    cout << r << "\n";
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