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

vector<int> opt(vector<int> p) {
    auto r = p;
    int n = p.size();
    for (int i=0; i<n; i++) {
        r[i] = p[p[i]];
    }
    return r;
}

int fpow(int x, ll p, int m) {
    int rt = 1;
    while (p) {
        if (p&1) rt = 1LL*rt*x%m;
        x = 1LL*x*x%m;
        p >>= 1;
    }
    return rt;
}

void sol() {
    ll n, k;
    cin >> n >> k;
    vector<int> p(n), usd(n);
    for (auto& i:p) cin >> i, i--;
    // cout << p << endl;
    vector<int> ans(n);
    for (int i=0; i<n; i++) if (!usd[i]) {
        usd[i] = 1;
        vector<int> cyc(1, i);
        int j = p[i];
        while (j != i) {
            cyc.push_back(j);
            usd[j] = 1;
            j = p[j];
        }
        // cout << cyc << endl;
        int len = cyc.size();
        int s = fpow(2, k, len);
        for (int i=0; i<len; i++) {
            ans[cyc[i]] = cyc[(i+s)%len]+1;
        }
    }
    // cout << ans << endl;
    for (int i:ans) {
        cout << i << " ";
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