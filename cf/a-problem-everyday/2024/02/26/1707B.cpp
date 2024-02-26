
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
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
    vector<int> a(n);
    for (auto& i:a) cin >> i;
    reverse(a.begin(), a.end());
    int z = 0;
    while (a.size() && a.back() == 0) a.pop_back(), z++;
    // cout << a << " " << z << endl;
    while (a.size() > 1) {
        vector<int> b;
        for (int i=1; i<a.size(); i++) {
            b.push_back(a[i-1]-a[i]);
        }
        if (z>0) {
            z--;
            b.push_back(a.back());
        }
        sort(b.rbegin(), b.rend());
        a = b;
        while (a.size() && a.back() == 0) a.pop_back(), z++;
        // cout << a << " " << z << endl;
    }
    // cout << "div ---- " << endl;
    cout << (a.size()?a[0]:0) << "\n";
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
