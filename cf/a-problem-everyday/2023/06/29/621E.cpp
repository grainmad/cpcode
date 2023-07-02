
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
using namespace std;

#define N 105

struct Matrix {
    int mat[N][N];
    int n;
    Matrix(int n) : n(n) { memset(mat, 0, sizeof(mat)); }
    inline void operator*=(const Matrix& o) {
        int ans[n][n] = {};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j])
                    for (int k = 0; k < n; k++)
                        ans[i][k] =
                            (ans[i][k] + (long long)(mat[i][j]) * o.mat[j][k]) %
                            MOD;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                mat[i][j] = ans[i][j];
    }
    void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
};
/*
    // a *= b^n
    for (; n; n >>= 1, b *= b)
        if (n & 1)
            a *= b;
    a.print();
*/

void sol() {
    int n, b, k, x;
    cin >> n >> b >> k >> x;
    vector<int> cnt(10);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cnt[t]++;
    }
    Matrix A(x), B(x);
    for (int i = 0; i < x; i++) {
        for (int j = 1; j < 10; j++) {
            B.mat[i][(i * 10 + j) % x] += cnt[j];
        }
    }
    A.mat[0][0] = 1;
    for (; b; b >>= 1, B *= B) {
        if (b & 1)
            A *= B;
    }
    cout << A.mat[0][k] << "\n";
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
