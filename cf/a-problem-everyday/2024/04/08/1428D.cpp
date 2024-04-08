
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
    int n;
    cin >> n;
    vector<int> a(n), c1, c2, c3;
    for (int& i:a) cin >> i;
    for (int i=n-1; i>=0; i--) {
        if (a[i] == 3) c3.push_back(i);
        if (a[i] == 2) c2.push_back(i);
        if (a[i] == 1) c1.push_back(i);
    }
    // cout << c1 << " " << c2 << " " << c3 << endl;
    int ok = 1;
    vector<int> vis(n);
    vector<pair<int,int>> ans;
    int r = 0;
    function<bool(int)> opt1 = [&](int i) {
        vis[i] = 1;
        c1.pop_back();
        ans.emplace_back(r++, i);
        return true;
    };
    function<bool(int)> opt2 = [&](int i) {
        vis[i] = 1;
        c2.pop_back();
        if (!c1.empty()) {
            ans.emplace_back(r, i);
            opt1(c1.back());
        } else {
            ok = 0;
            return false;
        }
        return true;
    };
    function<bool(int)> opt3 = [&](int i) {
        vis[i] = 1;
        c3.pop_back();
        int x = n;
        if (c1.size()) x = min(x, c1.back());
        if (c2.size()) x = min(x, c2.back());
        if (c3.size()) x = min(x, c3.back());
        if (x != n) {
            ans.emplace_back(r, i);
            ans.emplace_back(r++, x);
        }
        if (c1.size() && x == c1.back()) opt1(x);
        if (c2.size() && x == c2.back()) opt2(x);
        if (c3.size() && x == c3.back()) opt3(x);
        if (x == n) ok = 0;
        return ok;
    };
    for (int i=0; i<n; i++) {
        if (vis[i]) continue;
        if (a[i] == 1) {
            opt1(i);
        }
        if (a[i] == 2) {
            opt2(i);
        }
        if (a[i] == 3) {
            opt3(i);
        }
        if (!ok) break;
    }
    if (r > n) ok = 0;
    if (ok) {
        cout << ans.size() << "\n";
        for (auto [x, y]:ans) {
            cout << x+1 << " " << y+1 << "\n";
        }
    } else {
        cout << "-1\n";
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
