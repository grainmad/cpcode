#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

// #define MOD 1000000007
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

    template <class T>
    friend bool operator==(T o, Modint u) {
        return u == o;
    }
    template <class T>
    friend Modint operator+(T o, Modint u) {
        return u + o;
    }
    template <class T>
    friend Modint operator*(T o, Modint u) {
        return u * o;
    }
    template <class T>
    friend Modint operator-(T o, Modint u) {
        return Modint(o) - u;
    }
    template <class T>
    friend Modint operator/(T o, Modint u) {
        return Modint(o) / u;
    }

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
    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] != '1' && s[i] != '1') {
            cout << "-1\n";
            return;
        }
    }
    mint stp = 0;
    while (s.size() != 1) {
        stp++;
        if (s.back() != '1') {
            stp += stp * (s.back() - '0' - 1);
        }
        s.pop_back();
    }
    cout << stp << "\n";
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