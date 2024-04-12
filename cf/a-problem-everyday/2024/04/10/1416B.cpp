
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
    int n;
    cin >> n;
    vector<ll> a(n);
    ll s = 0;
    for (auto& i:a) {
        cin >> i;
        s += i;
    }
    if (s%n) {
        cout << "-1\n";
        return; 
    }
    s /= n;
    vector<vector<ll>> ans;

    auto mv = [&](int u, int v, int x) {
        ans.push_back({u+1, v+1, x});
        a[u] -= x*(u+1);
        a[v] += x*(u+1);
    };
    for (int i=1; i<n; i++) {
        if (a[i]%(i+1)) {
            mv(0, i, i+1-a[i]%(i+1));
        }
        mv(i, 0, a[i]/(i+1));
    }
    // 所有数都在1号
    for (int i=1; i<n; i++) {
        ans.push_back({1, i+1, s});
    }
    cout << ans.size() << "\n";
    for (auto& i:ans) {
        cout << i[0] << " " << i[1] << " " << i[2] << "\n";
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
