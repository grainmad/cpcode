#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 4
#define MOD 998244353
using namespace std;

// map<ll, ll> mp;

// ll fpow(ll x, ll p, ll m) {
//     ll rt = 1;
//     while (p) {
//         if (p & 1)
//             rt = rt * x % m;
//         x = x * x % m;
//         p >>= 1;
//     }
//     return rt;
// }

// ll f(ll a, ll x, ll m) {
//     if (x < 0)
//         return 0;
//     if (x == 0)
//         return 1;
//     if (mp.count(x))
//         return mp[x];
//     return mp[x] = (f(a, x / 2, m) +
//                     f(a, x - x / 2 - 1, m) * fpow(a, x / 2 + 1, m) % m) %
//                    m;
// }

// void sol() {
//     ll a, x, m;
//     cin >> a >> x >> m;
//     cout << f(a, x - 1, m) << endl;
//     // ll mod = (a - 1) * m; mod > 1e9 fpow会溢出
//     // cout << (fpow(a, x, mod) - 1) / (a - 1) % m << endl;
// }

struct Matrix {
    ll mat[N][N];
};
// a: n*n b: n*n
Matrix mul_matrix(Matrix a, Matrix b, int n, ll m) {
    Matrix res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res.mat[i][j] = 0;
            for (int k = 0; k < n; k++) {
                res.mat[i][j] += a.mat[i][k] * b.mat[k][j] % m;
                res.mat[i][j] %= m;
            }
        }
    }
    return res;
}
// a^p
Matrix pow_matrix(Matrix a, ll p, int n, ll m) {
    Matrix res;
    // 单位矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res.mat[i][j] = (i == j ? 1 : 0);
        }
    }
    while (p != 0) {
        if (p & 1)
            res = mul_matrix(a, res, n, m);
        a = mul_matrix(a, a, n, m);
        p >>= 1;
    }
    return res;
}

void sol() {
    /*
        a_x A 1 ^{x-1} a_1
        1   0 1        1
    */
    ll a, x, m;
    cin >> a >> x >> m;
    Matrix m1, m2, m3;

    m1.mat[0][0] = a;
    m1.mat[0][1] = 1;
    m1.mat[1][0] = 0;
    m1.mat[1][1] = 1;

    m2.mat[0][0] = 1;
    m2.mat[1][0] = 1;

    m1 = pow_matrix(m1, x - 1, 2, m);

    m3 = mul_matrix(m1, m2, 2, m);

    cout << m3.mat[0][0] << "\n";
}

int main() {
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