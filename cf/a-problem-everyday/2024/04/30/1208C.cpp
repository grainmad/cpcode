
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
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
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    int p = 0;
    for (int x=0; x<n; x+=4) {
        for (int y=0; y<n; y+=4) {
            for (int i=0; i<4; i++) {
                for (int j=0; j<4; j++) {
                    a[x+i][y+j] = p++;
                }
            }
        }
    }
    for (auto& i:a) {
        for (auto& j:i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    // for (int i=0; i<n; i++) {
    //     int x0 = 0, x1 = 0;
    //     for (int j=0; j<n; j++) {
    //         x0 ^= a[i][j];
    //         x1 ^= a[j][i];
    //     }
    //     if (x0 || x1) {
    //         cout << "NO\n";
    //     }
    // }
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
