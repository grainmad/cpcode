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


void sol() {
    int n;
    cin >> n;
    vector<int> a(n), vis(n);
    for (auto& i : a)
        cin >> i, vis[i]++;
    int p = 0;
    while (vis[p])
        p++;
    // cout << p << endl;
    int sp = 0;
    int mex = 0;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) {
        v[a[i]] = 1;
        while (v[mex])
            mex++;
        if (mex == p) {
            sp = i;
            break;
        }
    }
    // cout << v << endl;
    vector<int> v2(n + 1, 0);
    mex = 0;
    for (int i = sp + 1; i < n; i++) {
        v2[a[i]] = 1;
        while (v2[mex])
            mex++;
    }
    // cout << v2 << endl;
    if (mex != p) {
        cout << "-1\n";
    } else {
        cout << "2\n";
        cout << "1 " << sp + 1 << "\n";
        cout << sp + 2 << " " << n << "\n";
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