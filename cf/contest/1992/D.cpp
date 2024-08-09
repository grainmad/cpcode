#include <bits/stdc++.h>
// #define SINGLE_INPUT
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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s = "L"+s+"L";

    vector<int> nl(n+2, INF);
    for (int i=n; i>=0; i--) {
        if (s[i] != 'C' && s[i+1] == 'L') {
            nl[i] = i+1;
        } else if (s[i] == 'W') {
            nl[i] = nl[i+1];
        }
    }
    
    // cout << nl << endl;
    vector<int> f(n+2, INF);
    f[0] = 0;
    for (int i=0; i<=n+1; i++) {
        if (s[i] == 'L') {
            for (int j=i+1; j<=min(i+m, n+1); j++) {
                f[j] = f[i];
            }
        } else if (s[i] == 'W') {
            if (nl[i] != INF) {
                f[nl[i]] = min(f[nl[i]], nl[i]-i+f[i]);
            }
        }
    }
    // cout << f << endl;
    if (f[n+1] <= k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

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