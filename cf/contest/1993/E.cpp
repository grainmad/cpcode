#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
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


void sol() {
    int n, m;
    cin >> n >> m;
    vector a(n+1, vector<int>(m+1));
    auto fr = a, fc = a;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
            a[i][m] ^= a[i][j];
            a[n][j] ^= a[i][j];
            a[n][m] ^= a[i][j];
        }
    }
    auto solve_row = [&]() {
        int msk = (1<<m+1)-1;
        for (int rm = 0; rm<=n; rm++) { // fr[i][j] 不含i行j列的行贡献
            // 行贡献 最优化列的排列 m+1列中选m列
            vector f(m+1, vector<int>(1<<m+1, 1e9));
            // f[i][j] 最后一个选择i列，已经选择的列集合是j，最优值
            // f[i][j] = f[i'][j'] + \sum \limits_{c=0}{n-1} |a[c][i]-a[c][i']|
            for (int i=0; i<=m; i++) {
                f[i][1<<i] = 0;
            }
            for (int j=1; j<1<<m+1; j++) {
                if (j&(j-1)) // 至少有2位
                for (int i=0; i<=m; i++) {
                    if (!(j>>i&1)) continue;
                    int jj = j ^ (1<<i);
                    for (int ii=0; ii<=m; ii++) {
                        if (!(jj>>ii&1)) continue;
                        int d = 0;
                        for (int c=0; c<=n; c++) if(c != rm) d += abs(a[c][i]-a[c][ii]);
                        f[i][j] = min(f[i][j], f[ii][jj] + d);
                    }
                }
            }
            for (int j=0; j<=m; j++) {
                fr[rm][j] = 1e9;
                for (int c=0; c<=m; c++) {
                    fr[rm][j] = min(f[c][msk^1<<j], fr[rm][j]);
                }
            }
        }
    };
    auto solve_clo = [&]() {
        int msk = (1<<n+1)-1;
        for (int rm = 0; rm<=m; rm++) { // fc[i][j] 不含i行j列的列贡献
            // 列贡献 最优化行的排列 n+1行中选n行
            vector f(n+1, vector<int>(1<<n+1, 1e9));
            // f[i][j] 最后一个选择i行，已经选择的行集合是j，最优值
            // f[i][j] = f[i'][j'] + \sum \limits_{c=0}{m-1} |a[i][c]-a[i'][c]|
            for (int i=0; i<=n; i++) {
                f[i][1<<i] = 0;
            }
            for (int j=1; j<1<<n+1; j++) {
                if (j&(j-1)) // 至少有2位
                for (int i=0; i<=n; i++) {
                    if (!(j>>i&1)) continue;
                    int jj = j ^ (1<<i);
                    for (int ii=0; ii<=n; ii++) {
                        if (!(jj>>ii&1)) continue;
                        int d = 0;
                        for (int c=0; c<=m; c++) if (c != rm) d += abs(a[i][c]-a[ii][c]);
                        f[i][j] = min(f[i][j], f[ii][jj] + d);
                    }
                }
            }
            // 已经求出不含rm列的最优行排列，还需枚举不含j行
            for (int j=0; j<=n; j++) { 
                fc[j][rm] = 1e9;
                for (int c=0; c<=n; c++) {// 最终结束位c行
                    fc[j][rm] = min(f[c][msk^1<<j], fc[j][rm]);
                }
            }
        }
    };
    
    solve_row();
    solve_clo();
    int ans = 1e9;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            ans = min(ans, fr[i][j] + fc[i][j]);
        }
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