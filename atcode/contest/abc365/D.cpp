#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
#define INF 0x3f3f3f3f
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
        cout << "1\n";
        return ;
    }
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        if (s[i] == 'R') a[i] = 0;
        if (s[i] == 'P') a[i] = 1;
        if (s[i] == 'S') a[i] = 2;
    }
    auto check = [&](int x, int y) {
        if ((x-y+3)%3==1) return 1;
        if ((x-y+3)%3==2) return -1;
        return 0;
    };
    // int f[n][3][3];
    // memset(f, 0, sizeof(f));
    vector f(n, vector (3, vector<int>(3)));
    int ans = -INF;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (i == j) continue;
            int x = check(i, a[0]), y = check(j, a[1]);
            if (x == -1 || y == -1) {
                f[1][i][j] = -INF;
            } else {
                if (check(i, a[0]) == 1) f[1][i][j]++;
                if (check(j, a[1]) == 1) f[1][i][j]++;
            }
            ans = max(ans, f[1][i][j]);
            // cout << 1 << " " << i << " " << j << " = " << f[1][i][j] << "\n";
        }
    }
    for (int t=2; t<n; t++) {
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (i == j) continue;
                int x = check(i, a[t-1]), y = check(j, a[t]);
                if (x == -1 || y == -1) {
                    f[t][i][j] = -INF;
                } else {
                    f[t][i][j] = -INF;
                    for (int c=0; c<3; c++) {
                        if (c != i)
                            f[t][i][j] = max(f[t][i][j], f[t-1][c][i]);
                    }
                    if (check(j, a[t]) == 1) f[t][i][j]++;
                }
                ans = max(ans, f[t][i][j]);
                // cout << t << " " << i << " " << j << " = " << f[t][i][j] << "\n";
            }
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