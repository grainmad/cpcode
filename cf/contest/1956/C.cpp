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
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    vector<vector<int>> opt;
    for (int i = n; i >= 1; i--) {
        vector<int> o;
        o.push_back(1);
        o.push_back(i);
        for (int j = 1; j <= n; j++) {
            o.push_back(j);
            a[i - 1][j - 1] = j;
        }
        opt.emplace_back(o);
        o.clear();
        o.push_back(2);
        o.push_back(i);
        for (int j = 1; j <= n; j++) {
            o.push_back(j);
            a[j - 1][i - 1] = j;
        }
        opt.emplace_back(o);
    }
    ll s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s += a[i][j];
        }
    }
    // cout << a << endl;
    cout << s << " " << opt.size() << "\n";
    for (auto& i : opt) {
        for (auto& j : i) {
            cout << j << " ";
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