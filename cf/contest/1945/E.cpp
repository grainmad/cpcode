#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

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


void ck(vector<int> a, int x) {
    cout << a << endl;
    int l = 1, r = a.size();
    while (l+1 != r) {
        int m = l+r>>1;
        cout << l << " " << m << " " << r << " a[m]=" << a[m] << endl;
        if (a[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << a[l] << endl;
}

void sol() {
    int n, x;
    cin >> n >> x;
    // cout << "n=" << n << "x=" << x << endl;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    // cout << a << endl;
    int l = 1, r = n+1;
    vector<int> c;
    while (l+1 != r) {
        int m = l+r>>1;
        // cout << l << " " << m << " " << r << " a[m]=" << a[m] << endl;
        c.push_back(m);
        if (a[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    if (a[l] == x) {
        cout << "0\n";
        return ;
    }
    int in = 0;
    for (auto i:c) {
        if (a[i] == x) in = 1;
    }
    if (!in) {
        cout << "1\n";
        int xp = 1;
        while (a[xp] != x) xp++;
        cout << l << " " << xp << "\n";
        // swap(a[l], a[xp]);
        // ck(a, x);
    } else {
        int xp = 1;
        while (a[xp] != x) xp++; // xp 在c中
        auto check = [&](int x) { // 检查是否在c中
            for (auto i:c) {
                if (i == x) return true;
            }
            return false;
        };
        int lxp = 1;
        while (lxp <= n && a[lxp] >= x || check(lxp)) lxp++; // a[lxp]<x 且不在c中
        if (lxp > n) {
            cout << "1\n";
            cout << xp << " " << l << "\n";
            // swap(a[l], a[xp]);
            // ck(a, x);
        } else {
            cout << "2\n";
            cout << lxp << " " << xp << "\n"; // xp 不再c中
            cout << lxp << " " << l << "\n";
            // swap(a[lxp], a[xp]);
            // swap(a[lxp], a[l]);
            // ck(a, x);
        }
    }
    // cout << l << " " << r << endl;
    // cout << a[l] << "\n";
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