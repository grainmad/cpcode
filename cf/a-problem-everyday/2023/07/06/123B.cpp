
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

ll up(ll u, ll d) {
    if (u >= 0)
        return (u + d - 1) / d * d;
    return u / d * d;
}

ll dw(ll u, ll d) {
    if (u >= 0)
        return u / d * d;
    return (u - d + 1) / d * d;
}

void sol() {
    ll a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    ll p1 = x1 + y1, p2 = x2 + y2;
    if (p1 > p2)
        swap(p1, p2);
    ll q1 = x1 - y1, q2 = x2 - y2;
    if (q1 > q2)
        swap(q1, q2);
    ll ans1 = (dw(p2, 2 * a) - up(p1, 2 * a)) / (2 * a) + 1;
    ll ans2 = (dw(q2, 2 * b) - up(q1, 2 * b)) / (2 * b) + 1;
    cout << max(ans1, ans2) << "\n";
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
