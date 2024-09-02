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
    int n, q;
    cin >> n >> q;
    vector<int> ps(n+1);
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        ps[x]++;
    }
    for (int i=1; i<=n; i++) {
        ps[i] += ps[i-1];
    }
    int nd = (n+2)/2;
    vector<int> ans(n+1);
    for (int x=1; x<=n; x++) {
        int l = 0, r = x-1;
        while (l<r) {
            int m = l+r>>1;
            int c = 0;
            for (int i=0; i<=n; i+=x) {
                int s = ps[min(n, i+m)];
                if (i>0) s -= ps[i-1];
                c += s;
            }
            if (c >= nd) {
                r = m;
            } else {
                l = m+1;
            }
        }
        ans[x] = r;
    }
    for (int i=0; i<q; i++) {
        int x;
        cin >> x;
        cout << ans[x] << " ";
    }
    cout << "\n";
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