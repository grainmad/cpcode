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

vector<int> a = {0, 3, 1, 2};

int ask(int p1, int p2, int p3, int p4) {
    cout << "? " << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
    // if ((a[p1] | a[p2]) < (a[p3] | a[p4]))
    //     return -1;
    // if ((a[p1] | a[p2]) > (a[p3] | a[p4]))
    //     return 1;
    // return 0;
    string ans;
    cin >> ans;
    if (ans == "<")
        return -1;
    if (ans == ">")
        return 1;
    return 0;
}

void sol() {
    int n;
    cin >> n;
    int mxp = 0;
    for (int i = 1; i < n; i++) {
        int rt = ask(mxp, mxp, i, i);
        if (rt == -1)
            mxp = i;
    }
    int mn = 0;
    vector<int> v;
    v.push_back(0);
    for (int i = 1; i < n; i++) {
        int rt = ask(mxp, mn, mxp, i);
        if (rt == -1) {
            v.clear();
            v.push_back(i);
            mn = i;
        } else if (rt == 0) {
            v.push_back(i);
        }
    }
    int mnp = 0;
    for (int i = 1; i < v.size(); i++) {
        int rt = ask(v[mnp], v[mnp], v[i], v[i]);
        if (rt == 1)
            mnp = i;
    }
    cout << "! " << v[mnp] << " " << mxp << endl;
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