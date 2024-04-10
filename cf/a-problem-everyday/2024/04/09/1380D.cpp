
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
    ll n, m;
    cin >> n >> m;
    ll x, k, y;
    cin >> x >> k >> y;
    vector<ll> a(n), b(m+2, 0);
    for (auto& i:a) cin >> i;
    for (int i=1; i<=m; i++) {
        cin >> b[i];
    }
    ll p = 0;
    ll ans = 0;
    for (int i=1; i<=m+1; i++) {
        ll ca = 0, cm = 0;
        while (p<n && a[p] != b[i]) {
            ca++;
            cm = max(cm, a[p]);
            p++;
        }
        if (p == n && i<m) {
            cout << "-1\n";
            return ;
        }
        if (cm > max(b[i], b[i-1])) {
            if (ca < k) {
                cout << "-1\n";
                return ;
            }
            ans += x;
            ca -= k;
        }
        ans += ca/k*min(x, k*y)+ca%k*y;
        p = min(n, p+1);
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
