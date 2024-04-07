
#include <bits/stdc++.h>
// #define SINGLE_INPUT
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
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    auto opt = [&](map<ll,ll> itv, ll l, ll m, ll r=-1)->ll {
        // cout << "opt " << l << " " << m <<  " " << r << endl;
        if (--itv[m-l-1] == 0) itv.erase(m-l-1);
        if (a[n] != m) {
            if (--itv[r-m-1] == 0) itv.erase(r-m-1);
            itv[r-l-1]++;
        }
        // cout << itv << endl;
        // 放最后
        ll t = min(d-(m == a[n]?a[n-1]:a[n])-1, itv.begin()->first);
        // cout << "set last : " << t << endl;
        // 放最大间隔中间
        int mx = itv.rbegin()->first;
        if (--itv[mx] == 0) {
            itv.erase(mx);
        }
        itv[(mx+1)/2-1]++;
        itv[mx-(mx+1)/2]++;
        return max(itv.begin()->first, t);
    };
    map<ll,ll> itv;
    for (int i=1; i<=n; i++) {
        itv[a[i]-a[i-1]-1]++;
    }
    auto [mn, cnt] = *itv.begin();
    // cout << mn << " -- " << cnt << endl;
    if (cnt > 2) {
        cout << mn << "\n";
    } else if (cnt == 2) {
        for (int i=1; i<n; i++) {
            if (a[i] - a[i-1] - 1 == mn && a[i+1] - a[i] - 1 == mn) {
                cout << opt(itv, a[i-1], a[i], a[i+1]) << "\n";
                return ;
            }
        }
        cout << mn << "\n";
    } else {
        if (a[1]-a[0]-1 == mn) cout << opt(itv, a[0], a[1], a[2]) << "\n";
        else if (a[n]-a[n-1]-1 == mn) cout << max(opt(itv, a[n-2], a[n-1], a[n]), opt(itv, a[n-1], a[n])) << "\n";
        else
        for (int i=2; i<n; i++) {
            if (a[i] - a[i-1] - 1 == mn) {
                cout << max(opt(itv, a[i-2], a[i-1], a[i]), opt(itv, a[i-1], a[i], a[i+1])) << "\n";
                return ;
            }
        }
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
