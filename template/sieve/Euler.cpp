#include <bits/stdc++.h>
#define ll long long
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
    for (int i : p) {
        cout << i << " ";
    }
    cout << "\n";
    return p;
}

vector<int> least_prime_factor(int n) {  // 求n及以内的所有数的最小质因子
    vector<int> p;                       // 质数集合
    vector<int> lpf(n + 1);              // lpf[i] i的最小质因子
    for (int i = 2; i <= n; i++) {
        if (lpf[i] == 0) {
            p.push_back(i);
            lpf[i] = i;
        }
        for (int j = 0; 1LL * p[j] * i <= n; j++) {
            lpf[p[j] * i] = p[j];
            if (i % p[j] == 0)
                break;
        }
    }
    lpf[1] = 1;
    for (int i = 1; i <= n; i++) {
        // cout << i << " " << lpf[i] << endl;
        cout << lpf[i] << " ";
    }
    cout << "\n";
    return lpf;
}

// phi(n) 小于n的正整数中与n互质的个数。
vector<int> euler_phi(int n) {  // 求n及以内的欧拉函数
    vector<int> p;              // 质数集合
    vector<int> phi(n + 1);
    for (int i = 2; i <= n; i++) {
        if (phi[i] == 0) {
            p.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; 1LL * p[j] * i <= n; j++) {
            phi[p[j] * i] = (p[j] - 1) * phi[i];
            if (i % p[j] == 0) {
                phi[p[j] * i] = p[j] * phi[i];  // i 的最小质因子是p[j]
                break;
            }
        }
    }
    phi[1] = 1;
    for (int i = 1; i <= n; i++) {
        // cout << i << " " << phi[i] << endl;
        cout << phi[i] << " ";
    }
    cout << "\n";
    return phi;
}

// mu(1) = 1
// mu(i) = 0 i有多个相同的质因子
// mu(i) = (-1)^k i有k个互不相同的质因子。
vector<int> mobius(int n) {  // 求n及以内的莫比乌斯函数
    vector<int> p;           // 质数集合
    vector<int> cp(n + 1);   // cp[i] i为合数
    vector<int> mu(n + 1);
    for (int i = 2; i <= n; i++) {
        if (cp[i] == 0) {
            mu[i] = -1;
            p.push_back(i);
        }
        for (int j = 0; 1LL * p[j] * i <= n; j++) {
            cp[p[j] * i] = 1;
            mu[p[j] * i] = -mu[i];
            if (i % p[j] == 0) {
                mu[p[j] * i] = 0;
                break;
            }
        }
    }
    mu[1] = 1;
    for (int i = 1; i <= n; i++) {
        // cout << i << " " << mu[i] << endl;
        cout << mu[i] << " ";
    }
    cout << "\n";
    return mu;
}

vector<int> cnt_divisor(int n) {  // 求1到n的每个数各自的约数个数
    vector<int> p;                // 质数集合
    vector<int> cp(n + 1);        // cp[i] i为合数
    vector<int> lpf_cnt(n + 1);   // lpf_cnt[i] i的最小质因数的个数
    vector<int> div(n + 1);       // div[i] i的约数个数
    for (int i = 2; i <= n; i++) {
        if (cp[i] == 0) {
            p.push_back(i);
            lpf_cnt[i] = 1;
            div[i] = 2;
        }

        for (int j = 0; 1LL * p[j] * i <= n; j++) {
            cp[p[j] * i] = 1;
            // i不含质因子p[j]，所以p[j]*i的最小质因子个数为1
            lpf_cnt[p[j] * i] = 1;
            // 新增一个从未出现的质数p[j]，之前的因数都可以乘以p[j]产生新的因子
            div[p[j] * i] = div[i] * 2;
            if (i % p[j] == 0) {
                lpf_cnt[p[j] * i] = lpf_cnt[i] + 1;
                // div[p[j]*i] = div[i] / (lpf_cnt[i]+1) * (lpf_cnt[i]+2)
                div[p[j] * i] =
                    div[i] / lpf_cnt[p[j] * i] * (lpf_cnt[p[j] * i] + 1);
                break;
            }
        }
    }
    div[1] = 1;
    for (int i = 1; i <= n; i++) {
        // cout << i << ' ' << div[i] << "\n";
        cout << div[i] << " ";
    }
    cout << "\n";
    return div;
}

vector<ll> sum_divisor(int n) {  // 求1到n的每个数各自的约数的和
    vector<int> p;               // 质数集合
    vector<int> cp(n + 1);       // cp[i] i为合数
    // i的最小质因子为p，p的个数为s，则g[i] = p^0+p^1+p^2+...+p^s
    vector<ll> g(n + 1);
    vector<ll> div(n + 1);  // div[i] i的所有因子的和
    for (int i = 2; i <= n; i++) {
        if (cp[i] == 0) {
            p.push_back(i);
            g[i] = 1 + i;
            div[i] = 1 + i;
        }
        for (int j = 0; 1LL * p[j] * i <= n; j++) {
            cp[p[j] * i] = 1;
            g[p[j] * i] = p[j] + 1;
            div[p[j] * i] = div[i] * (p[j] + 1);
            if (i % p[j] == 0) {
                // p[j] 是i的最小质因子，若i有s个p[j]，现在有s+1个
                // g[i]*p[j]+1 = (p[j]^0+p[j]^1+...+p[j]^s)p[j]+1 = g[p[j]*i]
                g[p[j] * i] = g[i] * p[j] + 1;
                div[p[j] * i] = div[i] / g[i] * g[p[j] * i];
                break;
            }
        }
    }
    div[1] = 1;
    for (int i = 1; i <= n; i++) {
        // cout << i << ' ' << div[i] << "\n";
        cout << div[i] << " ";
    }
    cout << "\n";
    return div;
}

/*
https://oeis.org/


A000040		The prime numbers.
(Formerly M0652 N0241)
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163,
167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251,
257, 263, 269, 271

A020639		Lpf(n): least prime dividing n (when n > 1); a(1) = 1. Or,
smallest prime factor of n, or smallest prime divisor of n.
1, 2, 3, 2, 5, 2, 7, 2, 3, 2, 11, 2, 13, 2, 3, 2, 17, 2, 19, 2, 3, 2, 23, 2, 5,
2, 3, 2, 29, 2, 31, 2, 3, 2, 5, 2, 37, 2, 3, 2, 41, 2, 43, 2, 3, 2, 47, 2, 7, 2,
3, 2, 53, 2, 5, 2, 3, 2, 59, 2, 61, 2, 3, 2, 5, 2, 67, 2, 3, 2, 71, 2, 73, 2, 3,
2, 7, 2, 79, 2, 3, 2, 83, 2, 5, 2, 3, 2, 89, 2, 7, 2, 3, 2, 5, 2, 97

A000010		Euler totient function phi(n): count numbers <= n and prime to
n. (Formerly M0299 N0111)
1, 1, 2, 2, 4, 2, 6, 4, 6, 4, 10, 4, 12, 6, 8, 8, 16, 6, 18, 8, 12, 10, 22, 8,
20, 12, 18, 12, 28, 8, 30, 16, 20, 16, 24, 12, 36, 18, 24, 16, 40, 12, 42, 20,
24, 22, 46, 16, 42, 20, 32, 24, 52, 18, 40, 24, 36, 28, 58, 16, 60, 30, 36, 32,
48, 20, 66, 32, 44

A008683		Möbius (or Moebius) function mu(n). mu(1) = 1; mu(n) = (-1)^k if
n is the product of k different primes; otherwise mu(n) = 0.
1, -1, -1, 0, -1, 1, -1, 0, 0, 1, -1, 0, -1, 1, 1, 0, -1, 0, -1, 0, 1, 1, -1, 0,
0, 1, 0, 0, -1, -1, -1, 0, 1, 1, 1, 0, -1, 1, 1, 0, -1, -1, -1, 0, 0, 1, -1, 0,
0, 0, 1, 0, -1, 0, 1, 0, 1, 1, -1, 0, -1, 1, 0, 0, 1, -1, -1, 0, 1, -1, -1, 0,
-1, 1, 0, 0, 1, -1

A000005		d(n) (also called tau(n) or sigma_0(n)), the number of divisors
of n. (Formerly M0246 N0086)
1, 2, 2, 3, 2, 4, 2, 4, 3, 4, 2, 6, 2, 4, 4, 5, 2, 6, 2, 6, 4, 4, 2, 8, 3, 4, 4,
6, 2, 8, 2, 6, 4, 4, 4, 9, 2, 4, 4, 8, 2, 8, 2, 6, 6, 4, 2, 10, 3, 6, 4, 6, 2,
8, 4, 8, 4, 4, 2, 12, 2, 4, 6, 7, 4, 8, 2, 6, 4, 8, 2, 12, 2, 4, 6, 6, 4, 8, 2,
10, 5, 4, 2, 12, 4, 4, 4, 8, 2, 12, 4, 6, 4, 4, 4, 12, 2, 6, 6, 9, 2, 8, 2, 8

A000203		a(n) = sigma(n), the sum of the divisors of n. Also called
sigma_1(n). (Formerly M2329 N0921)
1, 3, 4, 7, 6, 12, 8, 15, 13, 18, 12, 28, 14, 24, 24, 31, 18, 39, 20, 42, 32,
36, 24, 60, 31, 42, 40, 56, 30, 72, 32, 63, 48, 54, 48, 91, 38, 60, 56, 90, 42,
96, 44, 84, 78, 72, 48, 124, 57, 93, 72, 98, 54, 120, 72, 120, 80, 90, 60, 168,
62, 96, 104, 127, 84, 144, 68, 126, 96, 144

*/

int main() {
    euler_sieve(100);
    least_prime_factor(100);
    euler_phi(100);
    mobius(100);
    cnt_divisor(100);
    sum_divisor(100);
}