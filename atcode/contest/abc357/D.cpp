#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
using namespace std;

random_device seed;
ranlux48 engine(seed());
int random(int l, int r) {
    uniform_int_distribution<> distrib(l, r);
    return distrib(engine);
}
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


#define N 5
#define MOD 998244353

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
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << mat[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        cout << mat[0][0] << "\n";
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
    ll n;
    cin >> n;
    ll t = n, b10 = 1;
    while (t) {
        b10 = b10*10%MOD;
        t /= 10;
    }
    Matrix a(2), b(2);
    a.mat[0][0] = 0;
    a.mat[0][1] = 1;
    b.mat[0][0] = b10;
    b.mat[1][0] = n%MOD;
    b.mat[1][1] = 1;

    for (; n; n >>= 1, b *= b)
        if (n & 1)
            a *= b;
    a.print();

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