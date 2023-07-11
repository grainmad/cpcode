
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

// 原理 每个合数都是由其最小质数所筛去
vector<int> euler_sieve(int n) {  // 求n及以内的质数
    vector<int> p;                // 质数集合
    vector<int> cp(n + 1);        // cp[i] i为合数
    for (int i = 2; i <= n; i++) {
        if (cp[i] == 0)
            p.push_back(i);
        for (int j = 0; 1LL * p[j] * i <= n; j++) {
            cp[p[j] * i] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
    // for (int i : p) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    // return p;
    return cp;
}

// void sol() {
//     ll n, m;
//     cin >> n >> m;
//     vector<int> cp = euler_sieve(n);
//     ll ans = 0, ca = 1, ok = 1, p = 1;
//     for (ll i = 1; i <= n; i++) {
//         ca *= m % MOD;
//         ca %= MOD;
//         if (p <= m && !cp[i])
//             p *= i;
//         if (p <= m) {
//             ok *= (m / p) % MOD;
//             ok %= MOD;
//         } else {
//             ok = 0;
//         }
//         ans += (ca - ok + MOD) % MOD;
//         ans %= MOD;
//     }
//     cout << ans << "\n";
// }

#define mint Modint<MOD>
template <const int _MOD>
struct Modint {
    int v;
    Modint() { v = 0; }
    Modint(long long o) { v = o % _MOD; }
    int val() { return v; }
    int pow(long long o) {
        int ret = 1, tmp = v;
        while (o) {
            if (o & 1)
                ret = ((long long)ret * tmp) % _MOD;
            o >>= 1;
            tmp = ((long long)tmp * tmp) % _MOD;
        }
        return ret;
    }
    void operator=(long long o) { v = o % _MOD; }
    bool operator==(long long o) const { return v == o; }
    bool operator==(Modint o) const { return v == o.v; }
    bool operator!=(long long o) const { return v != o; }
    bool operator!=(Modint o) const { return v != o.v; }
    bool operator<(long long o) const { return v < o; }
    bool operator<(Modint o) const { return v < o.v; }
    bool operator>(long long o) const { return v > o; }
    bool operator>(Modint o) const { return v > o.v; }
    bool operator<=(long long o) const { return v <= o; }
    bool operator<=(Modint o) const { return v <= o.v; }
    bool operator>=(long long o) const { return v >= o; }
    bool operator>=(Modint o) const { return v >= o.v; }

    Modint operator+(long long o) const { return *this + Modint(o); }
    Modint operator+(Modint o) const { return ((long long)v + o.v) % _MOD; }
    Modint operator*(long long o) const { return *this * Modint(o); }
    Modint operator*(Modint o) const { return (long long)v * o.v % _MOD; }

    Modint operator-(long long o) const { return *this - Modint(o); }
    Modint operator-(Modint o) const {
        return ((long long)v - o.v + _MOD) % _MOD;
    }

    Modint operator/(long long o) const { return *this / Modint(o); }
    Modint operator/(Modint o) const {
        return ((long long)v * o.pow(_MOD - 2)) % _MOD;
    }
    void operator+=(long long o) { *this = *this + o; }
    void operator+=(Modint o) { *this = *this + o; }
    void operator*=(long long o) { *this = *this * o; }
    void operator*=(Modint o) { *this = *this * o; }
    void operator-=(long long o) { *this = *this - o; }
    void operator-=(Modint o) { *this = *this - o; }
    void operator/=(long long o) { *this = *this / o; }
    void operator/=(Modint o) { *this = *this / o; }

    Modint operator^(long long o) { return Modint(pow(o)); }
    Modint operator^(Modint o) { return Modint(pow(o.v)); }

    void operator++() { *this = *this + 1; }
    void operator--() { *this = *this - 1; }
    void operator++(int k) { *this = *this + 1; }
    void operator--(int k) { *this = *this - 1; }

    template <const int T>
    friend std::istream& operator>>(std::istream& in, Modint<T>& modint) {
        ll x;
        in >> x;
        modint = Modint<T>(x);
        return in;
    }

    template <const int T>
    friend std::ostream& operator<<(std::ostream& os, const Modint<T>& modint) {
        os << modint.v;
        return os;
    }
};

void sol() {
    ll n, m;
    cin >> n >> m;
    vector<int> cp = euler_sieve(n);
    mint ans = 0, ca = 1, ok = 1;
    ll p = 1;
    for (ll i = 1; i <= n; i++) {
        ca *= m;
        if (p <= m && !cp[i])
            p *= i;
        if (p <= m) {
            ok *= (m / p);
        } else {
            ok = 0;
        }
        ans += ca - ok;
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
