#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#define ll long long
using namespace std;
#define print(a, b) cout << a << ": " << b << endl

// eculid
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// extend eculid , d = gcd(a,b) = ax+by
void ex_gcd(ll a, ll b, ll* d, ll* x, ll* y) {
    if (b == 0) {
        *d = a;
        *x = 1;
        *y = 0;
    } else {
        ex_gcd(b, a % b, d, x, y);
        ll t = *x;
        *x = *y;
        *y = t - (a / b) * (*y);
    }
}

// a^b%n
////a<n a*n < MAX  n*n < MAX
ll modular_exponentiation(ll a, ll b, ll n) {
    // ll c = 0, d = 1, t = b, k = 0;
    // while (t != 0)
    //     t >>= 1, k++;
    // for (int i = k; i >= 0; i--) {
    //     c *= 2;
    //     d = (d * d) % n;
    //     if (b & (1LL << i)) {
    //         c += 1;
    //         d = (d * a) % n;
    //     }
    // }
    // return d;
    ll rt = 1;
    while (b) {
        if (b & 1)
            rt = rt * a % n;
        a = a * a % n;
        b >>= 1;
    }
    return rt;
}

// is a^(n-1) = 1 (mod n)
bool witness(ll a, ll n) {
    ll u = n - 1, t = 0;
    while (u & 1 == 0)
        u >>= 1, t++;
    // n - 1 = 2^t * u

    ll x = modular_exponentiation(a, u, n);
    // 二次探测定理
    // 如果一个数p是质数，对于一个x∈(0,p)且x∈Z，方程x^2≡1(modp)的解有且只有两个：x=1或x=p−1。
    for (int i = 0; i < t; i++) {
        int xp = x;
        x = x * x % n;
        if (x == 1 && xp != 1 && xp != n - 1)
            return true;
    }
    if (x != 1)
        return true;
    return false;
}

// test n times a^(n-1) = 1 (mod n), rand a
bool miller_rabin(ll n, ll s) {
    for (int i = 0; i < s; i++) {
        ll a = time(NULL) * (ll)rand() % (n - 1) + 1;
        // cout << "a " << a << "n " << n << endl;
        if (witness(a, n))
            return false;
    }
    return true;
}

// rand big prime in 2^15
ll rand_prime(ll rd) {
    ll prime = time(NULL) * rd % (2LL << 15);
    while (!miller_rabin(prime, 10)) {
        prime++;
        // cout << prime << endl;
    }
    return prime;
}

// e*d = 1 (mod phi_n)  => e*d +k*phi_n = 1
//  rsa private key
ll private_key(ll e, ll phi_n) {
    ll d, x, y;
    ex_gcd(e, phi_n, &d, &x, &y);
    return (x + phi_n) % phi_n;
}

// rsa public key
ll public_key(ll phi_n) {
    ll e = rand();
    while (gcd(e, phi_n) != 1)
        e++;
    return e;
}

void test() {
    srand((unsigned int)time(NULL));
    ll p = rand_prime(rand());
    ll q = rand_prime(rand());
    ll e = rand_prime(rand());
    // public_key e>max(p,q)  so gcd(e, phi_n=(p-1)(q-1)) = 1
    if (p > e)
        swap(e, p);
    if (q > e)
        swap(e, q);
    ll n = p * q;
    ll phi_n = (p - 1) * (q - 1);
    // ll e = public_key(phi_n);
    ll d = private_key(e, phi_n);
    print("p", p);
    print("q", q);
    print("n", n);
    print("phi_n", phi_n);
    print("e", e);
    print("d", d);
    ll msg = 1314;
    ll code_msg = modular_exponentiation(msg, e, n);
    ll decode_msg = modular_exponentiation(code_msg, d, n);
    print("code_msg", code_msg);
    print("decode_msg", decode_msg);

    /*
        e*d = 1 (mod phi_n)
        m^e = c
        c^d = m
        m^{e*d} = m (mod n)
    */
}

ll pow_mod(ll a, ll b, ll n) {
    if (b == 0)
        return 1;
    ll ans = 0;
    ans = pow_mod(a, b / 2, n);
    ans = ans * ans % n;
    if (b % 2 == 1)
        ans = (ans * a) % n;
    return ans;
}

int main() {
    //	cout << pow_mod(2, 10, 2000);
    test();

    return 0;
}