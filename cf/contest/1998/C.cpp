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
    int n, k;
    cin >> n >> k;
    int low = (n+1)/2+1;
    vector<ll> a(n), b(n), idx(n);
    for (auto& i:a) cin >> i;
    for (auto& i:b) cin >> i;
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) {
        return a[x]==a[y] ? b[x]>b[y] : a[x] > a[y];
    });
    ll l = 0, r = 2e9+7;
    while (l<r) {
        ll m = (r-l)/2+l;
        ll up = 0, tk = k;
        for (int i:idx) {
            if (a[i] >= m) up++;
            else if (b[i] && tk >= m-a[i]) {
                tk -= m-a[i];
                up++;
            }
        }
        // cout << m << "\n";
        if (up>=low) {
            l = m+1;
        } else {
            r = m;
        }
    }
    ll m = r-1, tk = k;
    vector<ll> up;
    for (int i:idx) {
        if (a[i] >= m) up.push_back(a[i]);
        else if (b[i] && tk >= m-a[i]) {
            tk -= m-a[i];
            up.push_back(m);
        }
        if (up.size() == low) break;
    }
    ll ans = m + up[0];
    int fr = 0;
    while (fr<n && b[idx[fr]] == 0) fr++;
    if (fr<n) {
        a[idx[fr]] += k;
        sort(a.begin(), a.end());
        ans = max(ans, a.back()+a[n-low]);
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