
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
// #define MOD 998244353
// const ll MOD = 1e9+7;
using namespace std;

template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p) {
    return os<<'['<<p.first<<", "<<p.second<<']';
}
template<class t> ostream& operator<<(ostream& os,const vector<t>& v) {
    os<<'['; int s = 1;
    for(auto e:v) { if (s) s = 0; else os << ", "; os << e; }
    return os<<']';
}
template<class t,class u> ostream& operator<<(ostream& os,const map<t,u>& mp){
    os<<'{'; int s = 1;
    for(auto [x,y]:mp) { if (s) s = 0; else os << ", "; os<<x<<": "<<y; }
    return os<<'}';
}

#define MOD 1000000007
// #define MOD 998244353
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

// 计算 x, x+2, x+4, ..., x+2(c-1)
mint cpt(mint x, mint c) {
    return c*(x+c-1);
}

mint ps(ll x) {
    ll c = 1, i = 1, a = 1, b = 2;
    mint ans = 0;
    while (x>=c) {
        if (i%2) {
            ans += cpt(a, c);
            a += 2*c;
        } else {
            ans += cpt(b, c);
            b += 2*c;
        }
        x -= c;
        c <<= 1;
        i++;
    }
    if (i%2) ans += cpt(a, x);
    else ans += cpt(b, x);
    return ans;
}

void sol() {
    ll a, b;
    cin >> a >> b;
    cout << ps(b) - ps(a-1) << '\n';
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
