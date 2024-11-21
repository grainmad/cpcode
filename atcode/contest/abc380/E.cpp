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

struct Node_t {
    int l, r;
    mutable int v;

    Node_t(const int &il, const int &ir, const int &iv) : l(il), r(ir), v(iv) {}

    bool operator<(const Node_t &o) const { return l < o.l; }
};

set<Node_t> odt;

void sol() {
    int n, q;
    cin >> n >> q;
    vector<int> cnt(n+1, 1);
    for (int i=1; i<=n; i++) {
        odt.insert(Node_t(i,i,i));
    }
    // for (auto& [l, r, v]:odt) {
    //     cout << format("{} {} {}\n", l, r, v);
    // }
    while (q--) {
        int o, x, c;
        cin >> o;
        if (o == 1) {
            cin >> x >> c;
            auto it = --odt.upper_bound(Node_t{x, 0, 0});
            int l = it->l, r = it->r;
            cnt[it->v] -= r-l+1;
            cnt[c] += r-l+1;
            auto rit = it;
            auto lit = it;
            if (++rit != odt.end()) {
                if (rit->v == c) r = rit->r;
            }
            if (lit != odt.begin()) {
                --lit;
                if (lit->v == c) l = lit->l;
            }
            auto dlit = odt.lower_bound(Node_t(l, 0, 0));
            auto drit = odt.upper_bound(Node_t(r, 0, 0));
            while (dlit != drit) {
                odt.erase(dlit++);
            }
            
            odt.insert(Node_t(l, r, c));
            // for (auto& [l, r, v]:odt) {
            //     cout << format("end {} {} {}\n", l, r, v);
            // }
        } else {
            cin >> c;
            cout << cnt[c] << "\n";
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