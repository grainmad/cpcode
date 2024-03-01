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

vector<int> p;
int lpf[N];

void sieve() {
    lpf[1] = 1;
    for (int i = 2; i < N; i++) {
        if (lpf[i] == 0) {
            lpf[i] = i;
            p.push_back(i);
        }
        for (int j = 0; p[j] * i < N; j++) {
            lpf[p[j] * i] = p[j];
            if (i % p[j] == 0) {
                break;
            }
        }
    }
    // for (int i : p) {
    //     cout << i << "\n";
    // }
    // for (int i = 1; i < N; i++) {
    //     cout << i << " " << lpf[i] << "\n";
    // }
}

void sol() {
    sieve();
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    ll ans = 0, c0 = 0;

    vector<vector<pair<int, int>>> fac(n);
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (x == 0) {
            c0++;
            continue;
        }
        while (lpf[x] != 1) {
            if (fac[i].empty() || fac[i].back().first != lpf[x])
                fac[i].emplace_back(lpf[x], 1);
            else
                fac[i].back().second++;
            x /= lpf[x];
        }
        fac[i].emplace_back(1, 1);
        // cout << fac[i] << endl;
    }
    ans += c0 * (n - 1) - c0 * (c0 - 1) / 2;
    map<int, ll> mp;
    for (int i = 0; i < n; i++) {
        if (fac[i].size() == 0)
            continue;
        int t = 1;
        for (auto [x, y] : fac[i]) {
            if (y % 2 == 1)
                t *= x;
        }
        mp[t]++;
    }
    // cout << mp << endl;
    for (auto [x, y] : mp) {
        if (x != 0)
            ans += y * (y - 1) / 2;
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