
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

void sol() {
    int n;
    cin >> n;
    vector<ll> a(n+1), b(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i] >> b[i];
    }
    ll f[n+1][3];
    memset(f, 0x3f, sizeof(f));
    memset(f[0], 0, sizeof(f[0]));
    for (int i=1; i<=n; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                if (a[i-1] + k != a[i] + j)
                    f[i][j] = min(f[i][j],  f[i-1][k]+b[i]*j);
            }
        }
    }
    cout << min({f[n][0],f[n][1],f[n][2]}) << endl;
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
