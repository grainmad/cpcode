
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
    ll b, w;
    cin >> b >> w;
    if (b >= (w+1)/3 && w >= (b+1)/3) {
        cout << "YES\n";
        int mw = w > b;
        if (w > b) {
            swap(w, b);
        }
        int m1 = 0, m2 = 0, m3 = 0;
        vector<pair<int,int>> ans;
        for (int i=0, j=1; i<b; j+=2) {
            if (i++<b) {
                // cout << "2 " << j << "\n";
                ans.emplace_back(2, j);
                m2 = max(m2, j);
            }
            if (i++<b) {
                // cout << "1 " << j+1 << "\n";
                ans.emplace_back(1, j+1);
                m1 = max(m1, j+1);
            }
            if (i++<b) {
                // cout << "3 " << j+1 << "\n";
                ans.emplace_back(3, j+1);
                m3 = max(m3, j+1);
            }
        }
        // cout << m1 << " " << m2 << " " << m3 << endl;
        int cw = 0;
        for (int i=2; cw<w && i<=m2+1; i+=2, cw++) {
            ans.emplace_back(2, i);
        }
        for (int i=1; cw<w && i<=m1+1; i+=2, cw++) {
            ans.emplace_back(1, i);
        }
        for (int i=1; cw<w && i<=m3+1; i+=2, cw++) {
            ans.emplace_back(3, i);
        }
        // cout << ans.size() << " " << w << " " << b << endl;
        // cout << ans << endl;
        for (auto [x, y]:ans) {
            cout << x+mw << " " << y << "\n";
        }
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
