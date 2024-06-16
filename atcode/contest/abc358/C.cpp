#include <bits/stdc++.h>
#define SINGLE_INPUT
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
    vector<int> a;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        int b = 0;
        for (char i:s) {
            b <<= 1;
            if (i == 'o') b |= 1;
        }
        a.push_back(b);
    }
    // cout << a <<endl;
    int ans = n;
    for (int i=0; i<(1<<n); i++) {
        int cnt = 0, tans = 0;
        for (int j=0; j<n; j++) {
            if (i>>j&1) {
                cnt++;
                tans |= a[j];
            }
        }
        if (tans+1 == (1<<m)) ans = min(ans, cnt);
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