#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

template <class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
    return os << '[' << p.first << ", " << p.second << ']';
}
template <class t>
ostream& operator<<(ostream& os, const vector<t>& v) {
    os << '[';
    int s = 1;
    for (auto e : v) {
        if (s)
            s = 0;
        else
            os << ", ";
        os << e;
    }
    return os << ']';
}
template <class t, class u>
ostream& operator<<(ostream& os, const map<t, u>& mp) {
    os << '{';
    int s = 1;
    for (auto [x, y] : mp) {
        if (s)
            s = 0;
        else
            os << ", ";
        os << x << ": " << y;
    }
    return os << '}';
}

void sol() {
    int n, l, d;
    cin >> n >> l >> d;
    int sz = max(n, l + d - 1) + 5;
    vector<double> f(sz), g(sz), s1(sz, -1), s2(sz, -1);
    function<double(int)> ps1 = [&](int i) -> double {
        if (i < 0)
            return 0;
        if (s1[i] >= 0)
            return s1[i];
        return s1[i] = f[i] + ps1(i - 1);
    };
    auto rng1 = [&](int l, int r) -> double {
        if (l > r)
            return 0;
        return ps1(r) - ps1(l - 1);
    };
    function<double(int)> ps2 = [&](int i) -> double {
        if (i > n)
            return 0;
        if (s2[i] >= 0)
            return s2[i];
        return s2[i] = g[i] + ps2(i + 1);
    };
    auto rng2 = [&](int l, int r) -> double {
        if (l > r)
            return 0;
        return ps2(l) - ps2(r + 1);
    };
    f[0] = 1;
    for (int i = 1; i < sz; i++) {
        if (i >= l + d)
            f[i] = 0;
        else
            f[i] = rng1(i - d, min(l - 1, i - 1)) / d;
    }
    for (int i = n; i >= 0; i--) {
        g[i] = max(1 - rng1(max(i, l), n),
                   // rng1(l, min(l + d - 1, i - 1)) + rng1(n + 1, l + d - 1),
                   rng2(i + 1, i + d) / d);
    }
    cout << g[0] << "\n";
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