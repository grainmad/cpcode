
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f
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

ll pw(int x, int y) {
    ll rt = 1;
    for (int i=0; i<x; i++) rt *= 2;
    for (int i=0; i<y; i++) rt *= 3;
    return rt;
}

void sol() {
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n);
    for (auto& i:a) cin >> i;
    sort(a.begin(), a.end());
    ll f[n+1][3][2];
    memset(f, -1, sizeof(f));
    for (int i=0; i<=2; i++) {
        for (int j=0; j<=1; j++) {
            f[0][i][j] = h*pw(i,j);
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int g=0; g<=2; g++) {
            for (int b=0; b<=1; b++) {
                if (f[i][g][b] == -1) continue;
                for (int rg=g; rg<=2; rg++) {
                    for (int rb=b; rb<=1; rb++) {
                        if (f[i][g][b]*pw(rg-g, rb-b) > a[i]) {
                            ans = i+1;
                            f[i+1][rg][rb] = max(f[i][g][b]*pw(rg-g, rb-b)+a[i]/2, f[i+1][rg][rb]);
                        }    
                    }
                }
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
