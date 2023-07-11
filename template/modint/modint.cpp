#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 13
using namespace std;

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
    // 11 12 13 14
    mint a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << "a:" << a << " b:" << b << " c:" << c << " d:" << d << endl;
    cout << "a+b:" << a + b << endl;
    cout << "b+d:" << b + d << endl;
    // _MOD is prime , a is not 0
    cout << "a^-1:" << mint(1) / a << endl;
    cout << "a-b:" << a - b << endl;
    cout << "a-51:" << a - 51 << endl;
    c -= 3;
    cout << "c:" << c << endl;          // 0-3
    cout << "c^3:" << (c ^ 3) << endl;  // 1000%12
    cout << "a:" << a << " b:" << b << " c:" << c << " d:" << d << endl;
    cout << "a*b*c*d: " << a * b * c * d << endl;
    cout << "a^-1:" << 1 / a << endl;
    cout << "b^-1:" << 1 / b << endl;
    cout << "c^-1:" << 1 / c << endl;
    cout << "d^-1:" << 1 / d << endl;
    cout << "a/b*c/d: " << a / b * c / d << endl;
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