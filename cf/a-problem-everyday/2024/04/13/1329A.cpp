
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
    vector<ll> a(m);
    ll s = 0;
    for (ll& i:a) cin >> i, s+=i;
    int ok = (s>=n);
    for (int i=0; i<m; i++) {
        if (i+a[i] > n) ok = 0;
    }
    if (!ok) {
        cout << "-1\n";
    } else {
        // n-a[m-1] need m-1, n-a[m-1]-(m-1)
        vector<int> ans;
        ans.push_back(n-a[m-1]+1);
        ll r = n-a[m-1]-(m-1);
        for (int p = m-2;p>=0; p--) {
            ll sub = min(r, a[p]-1);
            r -= sub;
            ans.push_back(ans.back()-sub-1);
        }
        reverse(ans.begin(), ans.end());
        // cout << ans << "\n";
        // for (int i=0; i<m; i++) {
        //     cout << i << " " << ans[i] << " " << ans[i]+a[i]-1 << "\n";
        // }
        for (int i:ans) {
            cout << i << " ";
        }
        cout << "\n";
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
